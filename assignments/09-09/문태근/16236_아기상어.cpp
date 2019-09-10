#include <iostream>
#include <queue>

#define MAX_MAP_SIZE 20

using namespace std;

int N, M;
int field[MAX_MAP_SIZE][MAX_MAP_SIZE];
int size_of_shark = 2;

struct history
{
    history(int x, int y, int step) : x(x), y(y), step(step) {}
    int x, y;
    int step;
};

struct hunt_result
{
    int time;
    pair<int, int> fish_pos;
};

int compare(int x1, int y1, int x2, int y2)
{
    // 음수 : (x1, y1) 이 우선순위 높음
    // 양수 : (x2, y2) 가 우선순위 높음
    return (x1 * MAX_MAP_SIZE + y1) - (x2 * MAX_MAP_SIZE + y2);
}

hunt_result hunt_fish(int x_from, int y_from)
{
    int delta[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = {{false}};
    hunt_result result = {-1};
    queue<history> que;
    que.push(history(x_from, y_from, 0));

    while (!que.empty())
    {
        history current = que.front();
        que.pop();

        if (result.time != -1 && result.time < current.step)
            break;

        if (field[current.x][current.y] != 0 && field[current.x][current.y] < size_of_shark)
        {
            if (result.time == -1)
            {
                result.time = current.step;
                result.fish_pos.first = current.x;
                result.fish_pos.second = current.y;
            }
            else if (compare(result.fish_pos.first, result.fish_pos.second, current.x, current.y) > 0)
            {
                result.fish_pos.first = current.x;
                result.fish_pos.second = current.y;
            }
        }

        for (int d = 0; d < 4; d++)
        { // for each direction
            int x_next = current.x + delta[d][0];
            int y_next = current.y + delta[d][1];

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N)
                continue;

            if (!visited[x_next][y_next] && field[x_next][y_next] <= size_of_shark)
            {
                visited[x_next][y_next] = true;
                que.push(history(x_next, y_next, current.step + 1));
            }
        }
    }

    return result;
}

int main()
{
    int total_hunting_time = 0;
    int x, y;
    int eat_count = 0;

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == 9)
            {
                x = i, y = j;
                field[i][j] = 0;
            }
        }
    }

    while (true)
    {
        hunt_result result = hunt_fish(x, y);
        if (result.time < 0)
            break;

        total_hunting_time += result.time;
        x = result.fish_pos.first;
        y = result.fish_pos.second;

        field[x][y] = 0;
        eat_count++;

        if (eat_count >= size_of_shark)
        {
            eat_count = 0;
            size_of_shark++;
        }
    }
    cout << total_hunting_time << endl;
}
