#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int ver, hor;
    int time;
    int ACat;//아래쪽AC

    int **map;
    int **readyMap;
    int **map1;
    int **map2;

    cin >> ver >> hor >> time;

    map1 = (int **)malloc(sizeof(int *) * 50);
    for(int i = 0; i < 50; i++){
        map1[i] = (int *)malloc(sizeof(int) * 50);
    }
    map2 = (int **)malloc(sizeof(int *) * 50);
    for(int i = 0; i < 50; i++){
        map2[i] = (int *)malloc(sizeof(int) * 50);
    }

    for(int i = 0; i < ver; i++){
        for(int j = 0; j < hor; j++){
            cin >> map1[i][j];
            if(map1[i][j]==-1) ACat = i;
        }
    }
    
    map = map1;
    readyMap = map2;
    for(int t = 0; t < time; t++){
        //확산
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                readyMap[i][j] = 0;
            }
        }
        for(int i = 0; i < ver; i++){
            for(int j = 0; j < hor; j++){
                readyMap[i][j] += map[i][j];
                if(map[i][j] > 0){//not AC nor empty
                    int cnt = 0;
                    int div = map[i][j] / 5;
                    if(i > 0 && map[i-1][j] != -1){
                        readyMap[i-1][j] += div;
                        cnt++;
                    }
                    if(j > 0 && map[i][j-1] != -1){
                        readyMap[i][j-1] += div;
                        cnt++;
                    }
                    if(i < ver-1 && map[i+1][j] != -1){
                        readyMap[i+1][j] += div;
                        cnt++;
                    }
                    if(j < hor -1 && map[i][j+1] != -1){
                        readyMap[i][j+1] += div;
                        cnt++;
                    }
                    readyMap[i][j] -= div * cnt;
                }
            }
        }
/*
    cout << endl <<"hihi" << endl;
        for(int i = 0; i < ver; i++){
            for(int j = 0; j < hor; j++){
                cout << readyMap[i][j] << " ";
            }cout << endl;  
        }
        cout << endl << endl;
*/


        //이동
        for(int i = ACat - 3; i >= 0; i--){
            readyMap[i+1][0] = readyMap[i][0];
        }
        for(int j = 1; j < hor; j++){
            readyMap[0][j-1] = readyMap[0][j];
        }
        for(int i = 1; i < ACat; i++){
            readyMap[i-1][hor-1] = readyMap[i][hor-1];
        }
        for(int j = hor - 2; j > 0; j--){
            readyMap[ACat - 1][j+1] = readyMap[ACat -1][j];
        }readyMap[ACat-1][1] = 0;

        
        for(int i = ACat + 2; i < ver; i++){
            readyMap[i-1][0] = readyMap[i][0];
        }
        for(int j = 1; j < hor; j++){
            readyMap[ver-1][j-1] = readyMap[ver-1][j];
        }
        for(int i = ver - 2; i >= ACat; i--){
            readyMap[i+1][hor-1] = readyMap[i][hor-1];
        }
        for(int j = hor - 2; j > 0; j--){
            readyMap[ACat][j+1] = readyMap[ACat][j];
        }readyMap[ACat][1] = 0;

/*       
        cout << endl;
        for(int i = 0; i < ver; i++){
            for(int j = 0; j < hor; j++){
                cout << readyMap[i][j] << " ";
            }cout << endl;  
        }
        cout << endl << endl;
*/        
        int **temp = map;
        map = readyMap;
        readyMap = temp;
        
    }

    int misemeonji = 0;
    for(int i = 0; i < ver; i++){
        for(int j = 0; j < hor; j++){
            misemeonji += map[i][j];
        }
    }misemeonji += 2 ;

    cout << misemeonji << endl;

    for(int i = 0; i < 50; i++){
        free(map1[i]);
        free(map2[i]);
    }
    free(map1);
    free(map2);

    return 0;
}
