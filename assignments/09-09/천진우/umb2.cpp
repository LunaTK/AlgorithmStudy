#include <iostream>
#include <vector>
using namespace std;

char map[50][50];
int row, col;

int shortest(int x1, int y1, int x2, int y2){
	vector<int> x;
	vector<int> y;
	vector<int> d;
	int r,c;
	int m[50][50]={0};
	m[x1][y1]=1;

	x.push_back(x1);
	y.push_back(y1);
	d.push_back(0);

	while(1){
		if(x[0]-1==x2 && y[0]==y2) return d[0]+1;
		if(x[0]+1==x2 && y[0]==y2) return d[0]+1;
		if(x[0]==x2 && y[0]+1==y2) return d[0]+1;
		if(x[0]==x2 && y[0]-1==y2) return d[0]+1;
		if(x[0]-1 >= 0 && map[x[0]-1][y[0]]!='#' && m[x[0]-1][y[0]]==0){
			x.push_back(x[0]-1);
			y.push_back(y[0]);
			d.push_back(d[0]+1);
			m[x[0]-1][y[0]]=1;
		}
		if(x[0]+1 < row && map[x[0]+1][y[0]]!='#' && m[x[0]+1][y[0]]==0){
			x.push_back(x[0]+1);
			y.push_back(y[0]);
			d.push_back(d[0]+1);
			m[x[0]+1][y[0]]=1;

		}
		if(y[0]-1 >= 0 && map[x[0]][y[0]-1]!='#' && m[x[0]][y[0]-1]==0){
			x.push_back(x[0]);
			y.push_back(y[0]-1);
			d.push_back(d[0]+1);
			m[x[0]][y[0]-1]=1;
		}
		if(y[0]+1 < col && map[x[0]][y[0]+1]!='#' && m[x[0]][y[0]+1]==0){
			x.push_back(x[0]);
			y.push_back(y[0]+1);
			d.push_back(d[0]+1);
			m[x[0]][y[0]+1]=1;
		}
		x.erase(x.begin());
		y.erase(y.begin());
		d.erase(d.begin());
	}
}

int main(){
	int i,j,a,b,c;
	int sx,sy;
	int gx, gy;
	int num=0;
	int min=100000;
	int sum[120];
	int cnt=0;
	char ch;
	int dis[5][5]={0};
	int sxd[5];
	int xgd[5];
	int tmp1, tmp2;
	int tmp;
	vector<int> qx;
	vector<int> qy;

	cin >> col;
	cin >> row;


	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			cin >> ch;
			map[i][j]=ch;
		}
	}
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(map[i][j]=='X'){
				num++;
				qx.push_back(i);
				qy.push_back(j);
			}
			else if(map[i][j]=='S'){
				sx=i;
				sy=j;
			}
			else if(map[i][j]=='E'){
				gx=i;
				gy=j;
			}
		}
	}


	for(i=0; i<num; i++){
		for(j=0; j<num; j++){
			if(i==j) continue;
			dis[i][j] = shortest(qx[i],qy[i],qx[j],qy[j]);
		}
	}

	/*
	cout << "num: " << num << endl;///////////////////
	for(i=0; i<num; i++){
		cout << "i: " << i << endl;
		tmp1 = shortest(sx,sy,qx[i],qy[i]);
		tmp2 = shortest(gx,gy,qx[i],qy[i]);
		cout << "i: " << i << endl;
		sxd[i] = tmp1;
		xgd[i] = tmp2;
		cout << "i: " << i << endl;
	}
	///////////////////////////////////
	*/

	for(i=0; i<num; i++){
		sxd[i] = shortest(sx,sy,qx[i],qy[i]);
	}
	for(i=0; i<num; i++){
		xgd[i] = shortest(gx,gy,qx[i],qy[i]);
	}


	if(num==0){
		sum[0]=shortest(sx,sy,gx,gy);
		cout << sum[0] << endl;
		return 0;
	}
	cnt=0;


	//////////////////////////////////////////////////////////////////////////////////////////////
	for(i=0; i<num; i++){
		if(num==1){
			sum[cnt] = sxd[i]+xgd[i];
			cnt++;
			continue;
		}
		for(j=0; j<num; j++){
			if(j==i) continue;
			if(num==2){
				sum[cnt] = sxd[i]+dis[i][j]+xgd[j];
				cnt++;
				continue;
			}
			for(a=0; a<num; a++){
				if(a==j || a==i) continue;
				if(num==3){
					sum[cnt] = sxd[i]+dis[i][j]+dis[j][a]+xgd[a];
					cnt++;
					continue;
				}
				for(b=0; b<num; b++){
					if(b==j || b==i || b==a) continue;
					if(num==4){
						sum[cnt] = sxd[i]+dis[i][j]+dis[j][a]+dis[a][b]+xgd[b];
						cnt++;
						continue;
					}
					for(c=0; c<num; c++){
						if(c==j || c==i || c==a || c==b) continue;
						sum[cnt] = sxd[i]+dis[i][j]+dis[j][a]+dis[a][b]+dis[b][c]+xgd[c];
						cnt++;
					}
				}
			}
		}
	}
	min=sum[0];
	for(i=1; i<cnt; i++){
		if(min>sum[i]) min=sum[i];
	}
	cout << min << endl;

}
