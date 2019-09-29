#include <iostream>
#include <vector>
#define MAX_NUM 201

using namespace std;

int N, M; // cow, chooksa
/**
 * Graph for network flow (ford-fulkerson algorithm)
 * Source   | Cow       | Chooksa    | Sink
 * 0        | 1 ~ N     | N+1 ~ N+M  | N+M+1
*/
bool graph[MAX_NUM * 2][MAX_NUM * 2] = {{false}}; // [cow][chooksa]
int flow[MAX_NUM * 2][MAX_NUM * 2] = {{0}};
bool visited[MAX_NUM] = {false};
int sink;

bool dfs()
{
    vector<pair<int, int> > parent;
    fill(visited, visited + MAX_NUM, false);
    parent.push_back(pair<int, int>(0, -1));
    visited[0] = true;
    while (!parent.empty())
    {
        int from = parent.back().first;
        int to = parent.back().second;

        if (from == sink)
        {
            for (int i = 0; i < parent.size() - 1; i++)
            {
                if (graph[parent[i].first][parent[i + 1].first])
                {
                    flow[parent[i].first][parent[i + 1].first] = 1;
                }
                else
                {
                    graph[parent[i + 1].first][parent[i].first] = 0;
                }
            }
            return true;
        }
        else
        {
            int i;
            for (i = to + 1; i <= sink; i++)
            {
                if (!visited[i] &&
                    ((graph[from][i] && flow[from][i] == 0) || (graph[i][from] && flow[i][from] == 1)))
                {
                    parent.push_back(pair<int, int>(i, -1));
                    visited[i] = true;
                    break;
                }
            }
            if (i > sink)
            {
                visited[parent.back().second] = false;
                parent.pop_back();
            }
        }
    }
    return false;
}

int get_max_cow()
{
    int max_cow = 0;
    while (dfs())
        ;
    for (int i = 1; i <= N; i++)
    {
        max_cow += flow[0][i];
    }
    return max_cow;
}

int main(void)
{
    int chooksa;
    int count;

    cin >> N >> M;
    sink = N + M + 1;
    for (int cow = 1; cow <= N; cow++)
    {
        cin >> count;
        graph[0][cow] = true;
        for (int j = 0; j < count; j++)
        {
            cin >> chooksa;
            graph[cow][N + chooksa] = true;
        }
    }

    for (int c = N + 1; c <= N + M; c++)
    {
        graph[c][sink] = true;
    }

    cout << get_max_cow() << endl;
}
