#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v[201];
int visit[201];
int cowHome[201] = {0,};

bool findCowHome(int cow){
    int i;

    visit[cow] = 1;
    for(i=1;i<int(v[cow].size());i++){
        int tmp = v[cow][i];
        if(cowHome[tmp]==0) return true;
        else if(findCowHome(cowHome[tmp])){
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    int i,j,tmp,num;
    int answer =0;

    for(i=1;i<=n;i++){
        cin >> tmp;
        for(j=1;j<=tmp;j++){
            cin >> num;
            v[i].push_back(num);
        }
    }

    for(i=1;i<=n;i++){
        fill(visit,visit+n+1,0);
        if(findCowHome(i)) answer++;
    }

    cout << answer << endl;
    return 0;
}