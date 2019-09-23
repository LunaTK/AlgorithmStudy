#include <iostream>

using namespace std;

int main(){
    string input;

    cin >> input;

    int start = 0, end = input.size()-1;
    while(1){
        if(input[start] != input[end]) {
            cout << 0 <<endl;
            return 0;
        }
        if(start >= end ){
            cout << 1 << endl;
            return 0;
        }
        start++; end--;
    }


    return 0;
}