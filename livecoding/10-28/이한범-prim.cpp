#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define INF 100000000;
using namespace std;

int prim(int **map, int n){
    int dist[n];
    int parent[n];
    bool visit[n] = {0,};

    for(int i = 0 ; i < n ; i++){
        dist[i] = INF;
        parent[i] = -2;
    }

    dist[0] = 0;
    parent[0] = -1;
//    visit[0] = 1;

    for(int i = 0; i < n; i++){
        for(int i = 0; i < n; i++){
            cout << dist[i] << " " << parent[i] << " " << visit[i] << endl;
        }
        int small = INF;
        int where = -1;
        for(int j = 0; j < n; j++){
            if(visit[j]) continue;
            if(dist[j] < small){
                small = dist[j];
                where = j;
            }
        }

        visit[where] = 1;
        for(int i = 0; i < n; i++){
            if(map[where][i] && !visit[i]){
                if(map[where][i] < dist[i]){
                    dist[i] = map[where][i];
                    parent[i] = where;
                }
            }
        }
        
    }

    int span = 0;
    for(int i = 0; i < n; i++){
        span += dist[i];
    }
    return span;
}


int main(){

    int V, E;

    cin >> V >> E;

    int **map;
    /*
    for(int i = 0; i < E; i++){
        graph.push_back(vector<int> in);
    }
    */
    map = (int **)malloc(sizeof(int *)*V);
    for(int i = 0; i < V; i++){
        map[i] = (int *)malloc(sizeof(int)*V);
    }
    for(int i = 0; i < E; i++){
        int a, b, w;
        cin >> a >> b >> w;
        map[a-1][b-1] = w;
        map[b-1][a-1] = w;    
    }

    cout << prim(map, V) << endl;


    return 0;
}
