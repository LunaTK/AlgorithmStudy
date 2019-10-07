#include <iostream>
#include <queue>
#include <vector>

using namespace std;
queue<vector<int>> q;
vector<vector<int>> v;
int n;
int sea[21][21] ={0,};
int visit[21][21] = {0,};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int numFish=0;
struct shark{
    int x,y;
    int sharkSize=2;
    int ateFish=0;
    int time=0;
};
shark babyShark;

void eatFish(){
    if(v.empty()) return;

    int a=v[0][0],b;
    int i;
    fill(&visit[0][0],&visit[20][20],0);
    vector<int> temp;

    for(i=0;i<int(v.size());i++){
        if(v[i][0] <= a){
            a = v[i][0];
            b = v[i][1];
        }
    }

    for(i=0;i<int(v.size());i++){
        if(v[i][0] == a && v[i][1] < b) b = v[i][1];
    }

    babyShark.x = a;
    babyShark.y = b;
    babyShark.time += v[0][2];
    babyShark.ateFish++;

    if(babyShark.ateFish==babyShark.sharkSize){
        babyShark.sharkSize+=1;
        babyShark.ateFish = 0;
    }

    visit[babyShark.x][babyShark.y]=1;
    sea[babyShark.x][babyShark.y]=0;
    temp.push_back(babyShark.x);
    temp.push_back(babyShark.y);
    temp.push_back(0);

    //queue clear
    queue<vector<int>> empty;
    swap(q,empty);
    q.push(temp);
    //eat fish list clear
    v.clear();

}
void bfs(){
    int i,x,y,a,b,t;
    while(!q.empty()) {
        while (!q.empty()) {

            x = q.front()[0];
            y = q.front()[1];
            t = q.front()[2];
            q.pop();

            for (i = 0; i < 4; i++) {
                a = x + dx[i];
                b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < n) {
                    if (visit[a][b] == 0 && sea[a][b] <= babyShark.sharkSize) {
                        visit[a][b] = 1;
                        vector<int> temp;
                        temp.push_back(a);
                        temp.push_back(b);
                        temp.push_back(t + 1);
                        q.push(temp);

                        if (sea[a][b] != 0 && sea[a][b] < babyShark.sharkSize) {

                            if (v.empty()) v.push_back(temp);
                            else {
                                if (v[0][2] < t + 1) {
                                    eatFish();
                                    break;
                                } else {
                                    v.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
        eatFish();
    }

}
int main() {
    cin >> n;
    int i,j,tmp;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> tmp;
            if(tmp ==9){
                babyShark.x = i, babyShark.y =j;
                sea[i][j] =0;
            }
            else if(tmp==0) sea[i][j] =0;
            else {
                numFish++;
                sea[i][j] = tmp;
            }
        }
    }

    if(numFish==0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> temp;
    temp.push_back(babyShark.x);
    temp.push_back(babyShark.y);
    temp.push_back(0);
    q.push(temp);
    visit[babyShark.x][babyShark.y]=1;

    bfs();
    cout << babyShark.time << endl;

    return 0;
}