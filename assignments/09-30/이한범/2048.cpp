#include <iostream>
#include <stack>

using namespace std;

void makeMap(int **,int,int,stack<int**> &maps,stack<int> &depth);

int main(){

    int mapSize;

    cin >> mapSize;
    int** map = new int*[mapSize];

    for(int i = 0; i < mapSize; i++){
        map[i] = new int[mapSize];
        for(int j = 0; j < mapSize; j++){
            cin >> map[i][j];
        }
    }

    stack<int**> maps;
    stack<int> depth;

    maps.push(map);
    depth.push(0);

    int big = -1;
    while(!maps.empty()){
        int** mapNow = maps.top();
        int depthNow = depth.top();
        maps.pop();
        depth.pop();

//        cout << "stack size: " << maps.size();
//        cout << " depth : " << depthNow << endl;
        for(int i = 0; i < mapSize; i++){
            for(int j = 0; j < mapSize; j++){
//                cout << mapNow[i][j] << " ";
                if(mapNow[i][j] > big) big = mapNow[i][j];
            }
//            cout << endl;
        }
//        cout << endl;

        if(depthNow != 5) {
            depthNow++;
            makeMap(mapNow, mapSize, depthNow, maps, depth);
        }else continue;

        for(int i = 0; i < mapSize; i++) delete mapNow[i];
        delete mapNow;
    }
    cout << big << endl;
    return 0;
}

void makeMap(int** oldMap, int mapSize, int deep, stack<int**> &maps, stack<int> &depth){

    //left
    int noChange = 0;
    int remain = 1;
    int** newMapl = new int*[mapSize];
    for(int i = 0; i< mapSize; i++){
        newMapl[i] = new int[mapSize];
        int before = 0;
        int where = 0;
        for(int j = 0; j < mapSize; j++){
            if(oldMap[i][j] != 0){
                newMapl[i][where++] = oldMap[i][j];
                if(before == oldMap[i][j]) {
                    where--;
                    newMapl[i][where-1] = before * 2;
                    newMapl[i][where] = 0;
                    before = 0;
                    remain = 0;
                }
                else before = oldMap[i][j];
            }
        }
        for(int j = where; j < mapSize; j++){
            newMapl[i][j] = 0;
        }
        if(where == mapSize) noChange++;
    }
    if(noChange != mapSize){
        maps.push(newMapl);
        depth.push(deep);
//        cout << "left IN !!!"<<endl;
    }
/*    cout << "left" <<endl;
    for(int i = 0; i < mapSize; i++){
        for(int j = 0; j < mapSize; j++){
            cout << newMapl[i][j] <<" ";
        }
         cout << endl;
    }
    cout <<endl<<endl;
*/    //right
    noChange = 0;
    remain = 1;
    int** newMapr = new int*[mapSize];
    for(int i = 0; i< mapSize; i++){
        newMapr[i] = new int[mapSize];
        int before = 0;
        int where = mapSize-1;
        for(int j = mapSize - 1; j >= 0; j--){
            if(oldMap[i][j] != 0){
                newMapr[i][where--] = oldMap[i][j];
                if(before == oldMap[i][j]) {
                    where++;
                    newMapr[i][where+1] = before * 2;
                    newMapr[i][where] = 0;
                    before = 0;
                    remain = 0;
                }
                else before = oldMap[i][j];
            }
        }
        for(int j = where; j >=0 ; j--){
            newMapr[i][j] = 0;
        }
        if(where == -1) noChange++;
    }
    


    if(noChange != mapSize ){
        maps.push(newMapr);
        depth.push(deep);
//        cout << "rigth IN!!!"<< endl;
    }
/*    cout << "right" <<endl;
    for(int i = 0; i < mapSize; i++){
        for(int j = 0; j < mapSize; j++){
            cout << newMapr[i][j] <<" ";
        }
         cout << endl;
    }
    cout <<endl<<endl;
*/    //up
    noChange = 0;
    remain = 1;
    int** newMapu = new int*[mapSize];
    for(int i = 0; i < mapSize; i++) newMapu[i] = new int[mapSize];
    for(int j = 0; j < mapSize; j++){
        int before = 0;
        int where = 0;
        for(int i = 0; i < mapSize; i++){
            if(oldMap[i][j] != 0){
                newMapu[where++][j] = oldMap[i][j];
                if(before == oldMap[i][j]) {
                    where--;
                    newMapu[where-1][j] = before * 2;
                    newMapu[where][j] = 0;
                    before = 0;
                    remain = 0;
                }
                else before = oldMap[i][j];
            }
        }
        for(int i = where; i < mapSize; i++){
            newMapu[i][j] = 0;
        }
        if(where == mapSize) noChange++;
    }
    if(noChange != mapSize ){
        maps.push(newMapu);
        depth.push(deep);
//        cout << "up IN!!!" << endl;
    }
/*    cout << "up" <<endl;
    for(int i = 0; i < mapSize; i++){
        for(int j = 0; j < mapSize; j++){
            cout << newMapu[i][j] <<" ";
        }
         cout << endl;
    }
    cout <<endl<<endl;
*/    //down
    noChange = 0;
    remain = 1;
    int** newMapd = new int*[mapSize];
    for(int i = 0; i < mapSize; i++) newMapd[i] = new int[mapSize];
    for(int j = 0; j < mapSize; j++){
        int before = 0;
        int where = mapSize-1;
        for(int i = mapSize-1; i >= 0; i--){
            if(oldMap[i][j] != 0){
                newMapd[where--][j] = oldMap[i][j];
                if(before == oldMap[i][j]) {
                    where++;
                    newMapd[where+1][j] = before * 2;
                    newMapd[where][j] = 0;
                    before = 0;
                    remain = 0;
                }
                else before = oldMap[i][j];
            }
        }
        for(int i = where; i >= 0; i--){
            newMapd[i][j] = 0;
        }
        if(where == -1) noChange++;
    }
    if(noChange != mapSize ){
        maps.push(newMapd);
        depth.push(deep);
//        cout << "down IN!!!"<<endl;
    }
/*    cout << "down" <<endl;
    for(int i = 0; i < mapSize; i++){
        for(int j = 0; j < mapSize; j++){
            cout << newMapd[i][j] <<" ";
        }
         cout << endl;
    }
    cout <<endl<<endl;
*/
    return;
}
