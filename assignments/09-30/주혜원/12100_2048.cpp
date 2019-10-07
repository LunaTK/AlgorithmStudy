#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//0 - right,1-left,3,up,4-down
int n;
int M = -1;
int biggestBlock(int tmp[21][21]){
    int m = -1;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(tmp[i][j]>m){
                m = tmp[i][j];
            }
        }
    }
    return m;
}

void deleteZero(int dir,int arr[21][21]){
    int i,j;
    if(dir==0){//right
        for(i=0;i<n;i++){
            vector<int> v;
            for(j=0;j<n;j++){
                if(arr[i][j]!=0){
                    v.push_back(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            reverse(v.begin(),v.end());
            for(j=0;j<v.size();j++){
                arr[i][n-j-1] = v[j];
            }
        }
    }

    if(dir==1){//left
        for(i=0;i<n;i++){
            vector<int> v;
            for(j=0;j<n;j++){
                if(arr[i][j]!=0){
                    v.push_back(arr[i][j]);
                    arr[i][j] = 0;
                }
            }
            for(j=0;j<v.size();j++){
                arr[i][j] = v[j];
            }
        }
    }
    if(dir==2){//up
        for(i=0;i<n;i++){
            vector<int> v;
            for(j=0;j<n;j++){
                if(arr[j][i]!=0){
                    v.push_back(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            for(j=0;j<v.size();j++){
                arr[j][i] = v[j];
            }
        }
    }
    if(dir==3){//down
        for(i=0;i<n;i++){
            vector<int> v;
            for(j=0;j<n;j++){
                if(arr[j][i]!=0){
                    v.push_back(arr[j][i]);
                    arr[j][i] = 0;
                }
            }
            reverse(v.begin(),v.end());
            for(j=0;j<v.size();j++){
                arr[n-j-1][i] = v[j];
            }
        }
    }

}
void sumBlocks(int dir,int arr[21][21]){
    int i,j;
    if(dir==0){//right
        for(i=0;i<n;i++){
            for(j=n-1;j>0;j--){
                if(arr[i][j]!=0 && arr[i][j]==arr[i][j-1]){
                    arr[i][j] *= 2;
                    arr[i][j-1] = 0;
                    j--;
                }
            }
        }
        deleteZero(0,arr);
    }
    if(dir==1){//left
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                if(arr[i][j]!=0 && arr[i][j]==arr[i][j+1]){
                    arr[i][j] *= 2;
                    arr[i][j+1] = 0;
                    j++;
                }
            }
        }
        deleteZero(1,arr);
    }
    if(dir==2){//up
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                if(arr[j][i]!=0 && arr[j][i]==arr[j+1][i]){
                    arr[j][i] *= 2;
                    arr[j+1][i] = 0;
                    j++;
                }
            }
        }
        deleteZero(2,arr);
    }
    if(dir==3){//down
        for(i=0;i<n;i++){
            for(j=n-1;j>0;j--){
                if(arr[j][i]!=0 && arr[j][i]==arr[j-1][i]){
                    arr[j][i] *= 2;
                    arr[j-1][i] = 0;
                    j--;
                }
            }
        }
        deleteZero(3,arr);
    }
}

void backtrack(int count,int arr[21][21]){
    int tmp;

    int arr0[21][21] = {0,};
    int arr1[21][21] = {0,};
    int arr2[21][21] = {0,};
    int arr3[21][21] = {0,};

    copy(&arr[0][0], &arr[0][0] + (21 * 21), &arr0[0][0]);
    copy(&arr[0][0], &arr[0][0] + (21 * 21), &arr1[0][0]);
    copy(&arr[0][0], &arr[0][0] + (21 * 21), &arr2[0][0]);
    copy(&arr[0][0], &arr[0][0] + (21 * 21), &arr3[0][0]);

    if(count>0){
        tmp = biggestBlock(arr);
        if(tmp>M){
            //printArr(arr);
            M = tmp;
        }
    }
    if(count==5){
        //printArr(arr);
        return;
    }

    deleteZero(0,arr0);
    sumBlocks(0,arr0);
    backtrack(count+1,arr0);

    deleteZero(1,arr1);
    sumBlocks(1,arr1);
    backtrack(count+1,arr1);

    deleteZero(2,arr2);
    sumBlocks(2,arr2);
    backtrack(count+1,arr2);

    deleteZero(3,arr3);
    sumBlocks(3,arr3);
    backtrack(count+1,arr3);

}

int main() {
    cin >> n;
    int i,j;
    int arr[21][21] = {0,};

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    backtrack(0,arr);

    cout << M << endl;
    return 0;
}