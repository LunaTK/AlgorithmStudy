#include <iostream>
using namespace std;
int arr[51][51];
int t,r,c;
int upperAirConditioner;
int underAirConditioner;

void sparseDust(){
    int i,j,k,a,b;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int tmp[51][51] = {0,};

    for (i=0;i<r;i++) {
        for (j = 0; j < c; j++) {
            if(arr[i][j]>0){
                for(k=0;k<4;k++){
                    a = i+dx[k];
                    b = j+dy[k];
                    if(a>=0 && a<r && b>=0 && b<c && arr[a][b]!=-1){
                        tmp[a][b] += arr[i][j]/5;
                        tmp[i][j] -= arr[i][j]/5;
                    }
                }
            }
        }
    }

    for (i=0;i<r;i++) {
        for (j = 0; j < c; j++) {
            arr[i][j] += tmp[i][j];
        }
    }

}
void move(){
    int i;
    for(i=upperAirConditioner-1;i>0;i--){//down
        arr[i][0] = arr[i-1][0];
    }

    for(i=0;i<=c-2;i++){//left
        arr[0][i] = arr[0][i+1];
    }

    for(i=0;i<upperAirConditioner;i++){
        arr[i][c-1] = arr[i+1][c-1];//up
    }
    for(i=c-1;i>=2;i--){//right
        arr[upperAirConditioner][i] = arr[upperAirConditioner][i-1];
    }
    arr[upperAirConditioner][1] = 0;

    //under Air Conditioner
    for(i=underAirConditioner+1;i<=r-2;i++){//up
        arr[i][0] = arr[i+1][0];
    }
    for(i=0;i<=c-2;i++){//left
        arr[r-1][i] = arr[r-1][i+1];
    }
    for(i=r-1;i>underAirConditioner;i--){ // down
        arr[i][c-1] = arr[i-1][c-1];
    }
    for(i=c-1;i>=2;i--){ // right
        arr[underAirConditioner][i] = arr[underAirConditioner][i-1];
    }
    arr[underAirConditioner][1] =0;



}
int main() {
    cin >> r >> c >>t;
    int i,j;
    int dustSum=0;
    int cnt=0;
    for (i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> arr[i][j];
            if(arr[i][j]==-1 && cnt==0){
                upperAirConditioner = i;
                underAirConditioner = i+1;
                cnt++;
            }
        }
    }

    for(i=0;i<t;i++){

        sparseDust();
        move();

    }
    for (i=0;i<r;i++) {
        for (j = 0; j < c; j++) {
            if(arr[i][j]!=-1) dustSum+=arr[i][j];
        }
    }

    cout << dustSum << endl;

    return 0;
}