/**
 * Problem: 알파벳
 * URL: https://www.acmicpc.net/problem/1987
 * Author: 문태근
 */

#include <iostream>
#define NUM_OF_ALPHABET 26
#define MAX_SIZE 20
#define indexOf(X, Y) map[X][Y] - 'A'

using namespace std;

char map[MAX_SIZE][MAX_SIZE];
int R, C;
int maxDepth = 0;
bool visited[NUM_OF_ALPHABET];
int delta[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool isValidCoord(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(int x, int y, int depth) {
    if (!isValidCoord(x, y) || visited[indexOf(x, y)]) return;
    if (maxDepth < depth) {
        maxDepth = depth;
    }
    visited[indexOf(x, y)] = true;
    
    for (int i = 0; i < 4; i++) {
        dfs(x + delta[i][0], y + delta[i][1], depth+1);
    }
    
    visited[indexOf(x, y)] = false;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < NUM_OF_ALPHABET; i++) {
        visited[i] = false;
    }
    dfs(0, 0, 0);
    cout << (maxDepth+1) << endl;
    return 0;
}

