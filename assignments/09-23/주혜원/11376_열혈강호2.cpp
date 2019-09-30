#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v[1001];
int visit[1001];
int workNum[1001] ={0,};

bool findWork(int person){
    if(visit[person]!=0) return false;
    visit[person]=1;
    for(int i=0;i<v[person].size();i++){
        int personWork = v[person][i];
        if(workNum[personWork]==0 || findWork(workNum[personWork])){
            workNum[personWork] = person;
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    int i,j,work,tmp;
    int answer =0;
    for(i=1;i<=n;i++){
        cin >> work;
        for(j=0;j<work;j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    for(i=1;i<=n;i++){
        fill_n(visit,1001,0);
        if(findWork(i)) answer++;
        fill_n(visit,1001,0);
        if(findWork(i)) answer++;
    }

    cout << answer << endl;
    return 0;
}