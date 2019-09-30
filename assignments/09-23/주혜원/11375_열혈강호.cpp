#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v[1001];
int visit[1001];
int work[1001] = {0,};

bool dfs(int person){

    if(visit[person]!=0) return false;
    visit[person]=1;
    for(int i=0;i<int(v[person].size());i++){
        int tmp = v[person][i];
        if(work[tmp]==0 || dfs(work[tmp])){
            work[tmp] = person;
            return true;
        }

    }
    return false;
}

int main() {
    cin >> n >> m;
    int i,j,num,tmp;
    int answer=0;
    for(i=1;i<=n;i++){
        cin >> num;
        for(j=0;j<num;j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    for(i=1;i<=n;i++){
        fill_n(visit,1001,0);
        if(dfs(i)) answer++;

    }
    cout << answer << endl;
    return 0;
}