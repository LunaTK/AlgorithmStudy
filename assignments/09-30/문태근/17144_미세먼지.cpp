#include <iostream>
#define MAX_SIZE 51

using namespace std;

int R, C, T;
int field[MAX_SIZE][MAX_SIZE];
int diffuse_map[MAX_SIZE][MAX_SIZE];
int upper = -1, lower = -1;

bool valid(int x, int y) {
    return 0 <= x && x < R && 0 <= y && y < C;
}

int diffuse_one_cell(int i, int j) {
    int diffuse_count = 0;
    int amount = field[i][j] / 5;
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int d = 0; d < 4; d++) 
    {
        int x = i + delta[d][0];
        int y = j + delta[d][1];

        if (valid(x, y) && field[x][y] != -1) {
            diffuse_map[x][y] += amount;
            diffuse_count++;
        }
    }

    return amount * diffuse_count;
}

void build_diffuse_map() {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            diffuse_map[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (field[i][j] > 0) {
                field[i][j] -= diffuse_one_cell(i, j);
            }
        }
    }
}

void apply_diffuse_map() {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            field[i][j] += diffuse_map[i][j];
        }
    }
}

void diffuse_proc() {
    build_diffuse_map();
    apply_diffuse_map();
}


void flow_air(int from_x, int from_y, int flow[4][2]) {
    int x = from_x + flow[0][0];
    int y = from_y + flow[0][1];
    int current_dust = field[x][y];
    int next_dust;

    field[x][y] = 0;

    for (int d = 0; d < 4;) {
        int next_x = x + flow[d][0];
        int next_y = y + flow[d][1];

        if (!valid(next_x, next_y)) {
            d++;
            continue;
        } else if (!(next_x == from_x && next_y == from_y)) {
            next_dust = field[next_x][next_y];
            field[next_x][next_y] = current_dust;
            current_dust = next_dust;

            x = next_x;
            y = next_y;
        } else {
            break;
        }
    }
}

void purify_proc() {
    int flow_clockwise[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int flow_counter_clockwise[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    flow_air(upper, 0, flow_counter_clockwise);
    flow_air(lower, 0, flow_clockwise);
}

int total_dust() {
    int total_dust = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            total_dust += field[i][j];
        }
    }
    return total_dust + 2;
}

void debug() {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main(void) {
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == -1 && upper == -1) {
                upper = i;
            } else if (field[i][j] == -1) {
                lower = i;
            }
        }
    }
    
    for (int i = 0; i < T; i++)
    {
        diffuse_proc();
        purify_proc();
        debug();
    }
    
    cout << total_dust() << endl;
}
