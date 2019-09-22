#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int house_num, wifi_num;
    scanf("%d %d", &house_num, &wifi_num);

    long int house_locations[house_num];

    for(int i = 0; i < house_num; i++){
        scanf("%ld", &house_locations[i]);
    }
    sort(house_locations, &house_locations[house_num]);

    long int far = house_locations[house_num-1] - house_locations[0];

    long int prevFar = house_locations[house_num-1];

    bool not_find = 1;

    while(not_find){
        int cnt = 1;
        long int now = house_locations[0];
//        printf("%d ", house_locations[0]);
        for(int i = 0; i < house_num; i++){
            if(now + far <= house_locations[i]) {
                now = house_locations[i];
                cnt++;
//                printf(" %d ", now);
                if(cnt > wifi_num) break;
            }
        }

        if(cnt < wifi_num){
            long int temp = far;
            far = (far+1)/2;
            prevFar = temp;
        }
        else{
            long int temp = far;
            far = (far + prevFar + 1)/2;
            prevFar = temp;
        }
        if(prevFar == far) not_find = 0;
//        printf("\ncnt: %d far : %d\n\n", cnt, prevFar);
    }

    printf("%d\n", far);
    

}
