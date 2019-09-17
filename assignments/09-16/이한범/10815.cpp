#include <cstdio>
#include <cstdlib>

#define MAX_CARD 20000010

using namespace std;

char card[MAX_CARD];

int main(){
    int hand;
    int in;

    scanf("%d", &hand);

    for(int i = 0; i < hand; i++){
        scanf("%d", &in);
        if(in < 0) in = MAX_CARD + in;
        card[in] = 1;
    }

    int check_num;

    scanf("%d", &check_num);

    for(int i = 0; i < check_num; i++){
        scanf("%d", &in);
        if(in < 0) in = MAX_CARD + in;
        if(card[in]) printf("1 ");
        else printf("0 ");
    }
    return 0;
}
