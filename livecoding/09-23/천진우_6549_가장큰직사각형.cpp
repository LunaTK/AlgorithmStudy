#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    vector<int> height;
    int i,j;
    int tmpo;
    int n;
    int h=1;
    int size;
    vector<int> max;
    int flag=0;
    int cnt;
    int ans;
    int size2;
    vector<int> input;

    while(1){
        cin >> n;
        if(n==0) break;
        for(i=0; i<n; i++){
            cin >> tmpo;
            input.push_back(tmpo);
            height.push_back(tmpo);
        }
        height.erase(unique(height.begin(), height.end()), height.end());
        size = height.size();
        for(i=0; i<size; i++){
            cnt=0;
            max.push_back(0);
            flag=max.size();
            for(j=0; j<n; j++){
                if(input[j]>=height[i]){
                    cnt++;
                }
                else{
                    if(j!=0){
                        ans = cnt*height[i];
                        if(max[flag]<ans){
                            max[flag]=ans;
                            cnt=0;
                        }
                    }
                }
            }
            sort(max.begin(), max.end());
            size2 = max.size();
            cout << max[size2-1];

            if(i==size-1) break;
        }
    }
}