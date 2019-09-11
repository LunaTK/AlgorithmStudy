#include <iostream>
#include <vector>
using namespace std;

int map[20][20];
int row;

int choice(vector<int> x, vector<int> y){
	int size;
	int i,j;
	int minimum_x, minimum_y;
	vector<int> miny;

	minimum_x = x[0];
	size=x.size();
	for(i=1; i<size; i++){
		if(minimum_x>x[i]) minimum_x=x[i];
	}
	for(i=0; i<size; i++){
		if(x[i]==minimum_x){
			miny.push_back(y[i]);
		}
	}
	size=miny.size();
	minimum_y = miny[0];
	for(i=0; i<size; i++){
		if(minimum_y>miny[i]) minimum_y = miny[i];
	}
	return 100*minimum_x + minimum_y;
}

int find(int sx, int sy, int size){
	int i,j;
	int mx[4]={-1,0,0,1};
	int my[4]={0,-1,1,0};
	vector<int> x;
	vector<int> y;
	int m[20][20];
	int tx, ty, td;
	vector<int> dis;
	int min;
	int flag=0;
	vector<int> min_x;
	vector<int> min_y;
	int right_x, right_y;
	int tmp;
		
	for(i=0; i<row; i++){
		for(j=0; j<row; j++){
			m[i][j]=map[i][j];
		}
	}

	x.push_back(sx);
	y.push_back(sy);
	dis.push_back(0);
	m[sx][sy]=10000;

	while(1){//if vector is empty -> break
		if(x.size()==0){
			if(flag==0) return -1;
			else{
				tmp = choice(min_x, min_y);
				right_x = tmp/100;
				right_y = tmp%100;
				return min*10000 + right_x*100 + right_y;
			}
		}
		tx=x[0];
		ty=y[0];
		td=dis[0];
		x.erase(x.begin());
		y.erase(y.begin());
		dis.erase(dis.begin());


		for(i=0; i<4; i++){
			if((tx==0 && i==0) || (tx==row-1 && i==3) || (ty==0 && i==1) || (ty==row-1 && i==2)) continue;
			//goal
			if(1<=m[tx+mx[i]][ty+my[i]] && m[tx+mx[i]][ty+my[i]]<size){
//				return (td+1)*10000+(tx+mx[i])*100+(ty+my[i]);
				if(flag==0){
					flag=1;
					min=td+1;
					min_x.push_back(tx+mx[i]);
					min_y.push_back(ty+my[i]);

				}
				else{
					if(min==td+1){
						min_x.push_back(tx+mx[i]);
						min_y.push_back(ty+my[i]);
					}
					else{/////////////////////////////
						tmp = choice(min_x, min_y);
						right_x = tmp/100;
						right_y = tmp%100;
						return min*10000 + right_x*100 + right_y;
					}
				}
			}
			//not goal
			if(m[tx+mx[i]][ty+my[i]] <= size){
				if(flag==1){
					if(min<td+1){//////////////////////////////
						tmp = choice(min_x, min_y);
						right_x = tmp/100;
						right_y = tmp%100;
						return min*10000 + right_x*100 + right_y;
					}
				}
				x.push_back(tx+mx[i]);
				y.push_back(ty+my[i]);
				dis.push_back(td+1);
				m[tx+mx[i]][ty+my[i]] = 10000;
			}
		}
	}
}

int main(){
	int i,j;
	int size=2;
	int lo_x;
	int lo_y;
	int num_fish[7]={0};
	int smaller;
	int stack=0;
	int tmp, tmp1, tmp2;
	int time=0;
	cin >> row;
	for(i=0; i<row; i++){
		for(j=0; j<row; j++){
			cin >> map[i][j];
			if(map[i][j]==1){
				num_fish[1]++;
			}
			else if(map[i][j]==2){
				num_fish[2]++;
			}
			else if(map[i][j]==3){
				num_fish[3]++;
			}
			else if(map[i][j]==4){
				num_fish[4]++;
			}
			else if(map[i][j]==5){
				num_fish[5]++;
			}
			else if(map[i][j]==6){
				num_fish[6]++;
			}
			else if(map[i][j]==9){
				lo_x=i;
				lo_y=j;
				map[i][j]=0;
			}
		}
	}

	while(1){
		smaller=0;
		for(i=0; i<size; i++){
			smaller = smaller + num_fish[i];
		}
		if(smaller==0){
			break;;
		}
		
		else{
			tmp = find(lo_x, lo_y, size);
			if(tmp==-1){
				break;;
			}
			else{
				tmp2 = tmp/10000;
				time = time+tmp2;
				tmp1 = tmp%10000;
				lo_x = tmp1/100;
				lo_y = tmp1%100;
				map[lo_x][lo_y]=0;
				stack++;
				if(stack >= size){
					size++;
					stack=0;
				}
			}
		}
	}
	cout << time << endl;
	return 0;
}
