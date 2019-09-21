#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,len;
vector <int> card;
int answer[500001] = {0,};

bool isInCard(int start,int end,int a){

    if(start > end) return false;
    int mid = (start + end)/2;

    if(card[mid]==a) return true;
    else if(card[mid] < a) return isInCard(mid+1,end,a);
    else return isInCard(start,mid-1,a);
}


int main() {
    cin >> n;
    int i,a;
    for(i=0;i<n;i++){
        cin >> a;
        card.push_back(a);
    }
    sort(card.begin(),card.end());
    len = card.size();

    cin >> m;
    for(i=0;i<m;i++){
        cin >> a;
        if(isInCard(0,len-1,a)) answer[i]=1;
        else answer[i]=0;
    }

    for(i=0;i<m;i++){
        printf("%d ",answer[i]);
    }
    return 0;
}