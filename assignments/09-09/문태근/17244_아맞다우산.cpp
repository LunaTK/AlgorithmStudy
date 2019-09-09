#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_SIZE 50
#define MAX_NODE 5 + 2 // 물건 5개 + 출발지, 도착지

using namespace std;

typedef pair<int, int> point;

int N, M;
char field[MAX_SIZE][MAX_SIZE];

point position[MAX_NODE]; // 0번 : 출발지, 1번 : 도착지, 나머지 : 물건
int num_of_node = 2;      // 출발지, 도착지는 시작부터 포함

int graph[MAX_NODE][MAX_NODE];

struct history
{
    history(int x, int y, int step) : x(x), y(y), step(step) {}
    int x, y;
    int step;
};

int get_shortest_distance(point from, point to)
{
    int shortest_distance = -1;
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool visited[MAX_SIZE][MAX_SIZE] = {{false}};
    queue<history> que;

    que.push(history(from.first, from.second, 0));
    visited[from.first][from.second] = true;

    while (!que.empty())
    {
        history current = que.front();
        que.pop();

        if (current.x == to.first && current.y == to.second)
        {
            shortest_distance = current.step;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int x_next = current.x + delta[i][0];
            int y_next = current.y + delta[i][1];

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= M)
                continue;

            if (!visited[x_next][y_next] && field[x_next][y_next] != '#')
            {
                que.push(history(x_next, y_next, current.step + 1));
                visited[x_next][y_next] = true;
            }
        }
    }
    return shortest_distance;
}

int get_shortest_path_length()
{
    int shortest_path_length = 999999999;
    int loot_sequence[num_of_node];

    loot_sequence[0] = 0;
    for (int i = 1; i < num_of_node - 1; i++)
    {
        loot_sequence[i] = i + 1;
    }
    loot_sequence[num_of_node - 1] = 1;

    do
    {
        int path_length = 0;
        for (int i = 0; i < num_of_node - 1; i++)
        {
            path_length += graph[loot_sequence[i]][loot_sequence[i + 1]];
        }
        if (shortest_path_length > path_length && path_length > 0)
            shortest_path_length = path_length;
    } while (next_permutation(loot_sequence + 1, loot_sequence + num_of_node - 1));

    return shortest_path_length;
}

void build_graph()
{
    for (int i = 0; i < num_of_node; i++)
    {
        for (int j = 0; j < num_of_node; j++)
        {
            graph[i][j] = graph[j][i] = get_shortest_distance(position[i], position[j]);
        }
    }
}

int main()
{
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 'S')
            {
                position[0].first = i;
                position[0].second = j;
            }
            else if (field[i][j] == 'E')
            {
                position[1].first = i;
                position[1].second = j;
            }
            else if (field[i][j] == 'X')
            {
                position[num_of_node].first = i;
                position[num_of_node].second = j;
                num_of_node++;
            }
        }
    }

    build_graph();

    cout << get_shortest_path_length() << endl;
}
