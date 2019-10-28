#include <iostream>
#include <vector>
#define MAX_VERTICE 10001

using namespace std;

int n, m;
int graph[MAX_VERTICE][MAX_VERTICE];

struct Edge {
    int from, to, weight;
    Edge(int from, int to, int weight): from(from), to(to), weight(weight) {}
};

bool compare(Edge &a, Edge &b) {
    return a.weight < b.weight;
}

vector<Edge> edges;

void unify(int group[MAX_VERTICE], int g1, int g2) {
    for (int i = 1; i <= n; i++) {
        if (group[i] == g1) {
            group[i] = g2;
        }
    }
}

int mst_cost() {
    int group[MAX_VERTICE];
    int gid = 0;
    int cost = 0;
    
    fill(group, group + MAX_VERTICE, 0);

    for (Edge &e : edges) {
        if (group[e.from] == 0 && group[e.to] == 0) {
            group[e.from] = group[e.to] = ++gid;
        } else if (group[e.from] == 0) {
            group[e.from] = group[e.to];
        }  else if (group[e.to] == 0) {
            group[e.to] = group[e.from];
        } else if (group[e.from] != group[e.to]) {
            unify(group, e.from, e.to);
        } else {
            continue;
        }
        cost += e.weight;
    }
    return cost;
}

int main(void) {
    int a, b, c;
    
    cin >> n >> m;

    fill(graph[0], graph[0] + MAX_VERTICE * MAX_VERTICE, 0);

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
        edges.push_back(Edge(a, b, c));
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    cout << mst_cost() << endl;
}
