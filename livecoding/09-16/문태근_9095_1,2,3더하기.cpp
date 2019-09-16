#include <iostream>
#define MAX_INPUT 11

using namespace std;

int answer[MAX_INPUT] = {0, 1, 2, 4};

int main() {
    int test_n, n;
    
    for (int i = 4; i < MAX_INPUT; i++) {
        answer[i] = answer[i-1] + answer[i-2] + answer[i-3];
    }
    
    cin >> test_n;
    
    for (int t = 0; t < test_n; t++) {
        cin >> n;
        cout << answer[n] << endl;
    }
}
