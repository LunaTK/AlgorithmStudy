#include <cstdio>
#include <vector>

using namespace std;

vector< pair<int, int> > stack;
long long int max_surface = 0;

void pop_higher(int height, int before) {
    int size = stack.size();
    for (int i = size - 1; i >= 0; i--) {
        int h = stack[i].first;
        int idx = stack[i].second;
        if (h <= height) {
            break;
        }    
        long long int surface = (long long int)(before - idx) * h;
        if (i == 0) {
            surface += (long long int)h * idx;
         } else if (stack[i-1] < stack[i]) {
            surface += (long long int)h * (idx - stack[i-1].second - 1);
         }
        if (max_surface < surface) {
            max_surface = surface;
        }
        stack.pop_back();
    }
}

void pop_higher_and_push(int height, int before) {
    pop_higher(height, before);
    stack.push_back(pair<int,int>(height, before));
}


int main(void) {
    int n, h;

    scanf("%d", &n);
    while (n != 0) {
        max_surface = 0;
        stack.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &h);
            pop_higher_and_push(h, i);
        }
        pop_higher_and_push(0,n);
        printf("%lld\n", max_surface);

        scanf("%d", &n);
    }
}


