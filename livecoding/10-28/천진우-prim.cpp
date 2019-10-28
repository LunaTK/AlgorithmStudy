#include <iostream>
#include <vector>
using namespace std;

vector<int> *node;
vector<int> *cost;
int *arr;
int *visit;
int main(){
	int n,m;
	int i,j;
	int n1, n2, n3;
	int now;
	int sum=0;
	int min;
	int cnt=1;
	int choose;
	int ch_cost;
	cin >> n >> m;
	arr = new int[n+1];
	visit = new int[n+1];
	node = new vector<int>[n+1];
	cost = new vector<int>[n+1];
	for(i=0; i<m; i++){
		cin >> n1 >> n2 >> n3;
		node[n1].push_back(n2);
		cost[n1].push_back(n3);
		node[n2].push_back(n1);
		cost[n2].push_back(n3);
	}

	arr[0]=2000000;
	visit[0]=1;
	for(i=1; i<n+1; i++){
		visit[i]=0;
		arr[i]=2000000;
	}
	arr[1]=0;
	visit[1]=1;
	now = 1;
	while(1){
		if(cnt==n) break;
		for(i=0; i<node[now].size(); i++){
			if(cost[now][i] < arr[node[now][i]]){
				arr[node[now][i]] = cost[now][i];
			}
		}
		min = 2000000;
		for(i=1; i<n+1; i++){
			if(visit[i]==0){
				if(min > arr[i]){
					choose = i;
					min = arr[i];
					ch_cost = min;
				}
			}
		}
		visit[choose]=1;
		sum += ch_cost;
		cnt++;
		now = choose;

	}
	cout << sum << endl;
}
