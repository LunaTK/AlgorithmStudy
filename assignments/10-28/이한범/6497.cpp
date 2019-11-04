#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

uint prim(vector<int> map[], vector<int> cost[], int n){
    bool visited[n];
    uint dist[n];
    for(int i = 0; i < n; i++){
        dist[i] = UINT32_MAX;
        visited[i] = 0;
    }

    dist[0] = 0;

    for(int i = 0; i < n; i++){
        int small = UINT32_MAX;
        int where = 0;
        for(int j = 0; j < n; j++){
            if(visited[j]) continue;
            if(dist[j] < small){
                small = dist[j];
                where = j;
            }
        }
        visited[where] = 1;
        for(int c = 0; c < map[where].size(); c++){
            if(visited[map[where][c]]) continue;
            if(dist[map[where][c]] > cost[where][c]){
                dist[map[where][c]] = cost[where][c];
            }
        }

    }

    uint span = 0;

    for(int i = 0; i < n; i++){
        span += dist[i];
    }

    return span;
}

int main(){

    while(1){
        int N,V;

        cin >> N;
        cin >> V;

        if(N == 0) break;
        vector<int> map[N];
        vector<int> cost[N];
        uint whole_cost = 0;
        for(int i = 0; i < V; i++){
            int to, from, val;
            cin >> from >> to >> val;

            map[from].push_back(to);
            cost[from].push_back(val);

            map[to].push_back(from);
            cost[to].push_back(val);

            whole_cost += val;
        }

        cout << whole_cost - prim(map, cost, N) << endl;
    }


    return 0;
}
