#include <iostream>
#include <queue>

using namespace std;

typedef struct coord{
	int x;
	int y;
	int cost;
}coord;

typedef struct A_node{
	vector<int> num;
	int cost;
	int h_cost;
}A_node;

struct cmp{
	bool operator()(A_node t, A_node u){
		return t.cost + t.h_cost > u.cost + u.h_cost;
	}
};

vector<coord> X_coord;
coord S_coord, E_coord;
int X_count=0, N, M;
char** arr;
int** cost;

//bfs로 모든 S,X,E들 간의 거리 구하기
int findcost(int x, int y){
	queue<coord> q;
	int cur_x, cur_y;
	coord cur_coord, goal_coord;
	
	if(x == 0){
		cur_coord = S_coord;
		cur_coord.cost = 0;
		q.push(S_coord);
	}
	else if(x <= X_count){
		cur_coord = X_coord[x-1];
		cur_coord.cost = 0;
		q.push(X_coord[x-1]);
	}
	else{
		cur_coord = E_coord;
		cur_coord.cost=0;
		q.push(E_coord);
	}


	if(y <= X_count){
		goal_coord = X_coord[y-1];
	}
	else{
		goal_coord = E_coord;
	}

	
	while(!q.empty()){
		cur_coord = q.front();
		q.pop();

		if(cur_coord.x == goal_coord.x && cur_coord.y == goal_coord.y){
			return cur_coord.cost;
		}


		cur_x = cur_coord.x;
		cur_y = cur_coord.y;

		if(cur_x!=0 && arr[cur_x-1][cur_y]!='#'){
			coord temp_coord;
			temp_coord.x = cur_x-1;
			temp_coord.y = cur_y;
			temp_coord.cost = cur_coord.cost+1;
			q.push(temp_coord);
		}
		if(cur_y!=0 && arr[cur_x][cur_y-1]!='#'){
			coord temp_coord;
			temp_coord.x = cur_x;
			temp_coord.y = cur_y-1;
			temp_coord.cost = cur_coord.cost+1;
			q.push(temp_coord);
		}
		if(cur_x!=M-1 && arr[cur_x+1][cur_y]!='#'){
			coord temp_coord;
			temp_coord.x = cur_x+1;
			temp_coord.y = cur_y;
			temp_coord.cost = cur_coord.cost+1;
			q.push(temp_coord);
		}
		if(cur_y!=N-1 && arr[cur_x][cur_y+1]!='#'){
			coord temp_coord;
			temp_coord.x = cur_x;
			temp_coord.y = cur_y+1;
			temp_coord.cost = cur_coord.cost+1;
			q.push(temp_coord);
		}

	}

}
//A*로 최단경
int getresult(){

	priority_queue<A_node,vector<A_node>,cmp> pq;

	A_node first_node, cur_node;
	first_node.num.push_back(0);
	first_node.cost = 0;
	first_node.h_cost = X_count+1;
	pq.push(first_node);
	
	while(!pq.empty()){
		cur_node = pq.top();
		pq.pop();

		if(cur_node.num.size() == X_count+2){
			for(int i=0;i<cur_node.num.size();i++){
				cout << cur_node.num[i] << " ";
			}
			return cur_node.cost;
		}
		else if(cur_node.num.size() == X_count+1){
			A_node temp_node;
			for(int i=0;i<cur_node.num.size();i++){
				temp_node.num.push_back(cur_node.num[i]);
			}
			temp_node.cost = cur_node.cost + cost[cur_node.num.back()][X_count+1];
			temp_node.h_cost = 0;
			temp_node.num.push_back(X_count+1);
			pq.push(temp_node);
		}
		else{
			vector<int> unvisit;
			for(int i=0;i<X_count+1;i++){
				unvisit.push_back(i);
			}
			for(int i=0;i<cur_node.num.size();i++){
				for(int j=0;j<unvisit.size();j++){
					if(unvisit[j] == cur_node.num[i]){
						unvisit.erase(unvisit.begin()+j);
					}
				}
			}
			for(int i=0;i<unvisit.size();i++){
				A_node temp_node;
				for(int j=0;j<cur_node.num.size();j++){
					temp_node.num.push_back(cur_node.num[j]);
				}
				temp_node.cost = cur_node.cost + cost[cur_node.num.back()][unvisit[i]];
				temp_node.h_cost = cur_node.h_cost-1;
				temp_node.num.push_back(unvisit[i]);
				pq.push(temp_node);
			}
		}
	}
}

int main(int argc, char* argv[]){
	int temp_cnt, result;

	cin >> N >> M;
	arr = new char*[M];
	for(int i=0;i<M;i++){
		arr[i] = new char[N];
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'X'){
				X_count++;
			}
		}
	}
	temp_cnt = X_count; 

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] == '#'){
			}
			else if(arr[i][j] == '.'){
			}
			else if(arr[i][j] == 'S'){
				S_coord.x = i;
				S_coord.y = j;
			}
      		else if(arr[i][j] == 'X'){
				coord temp;
				temp.x = i;
				temp.y = j;
				X_coord.push_back(temp);
			}
			else if(arr[i][j] == 'E'){
				E_coord.x = i;
				E_coord.y = j;
			}
		}
	}

	
	cost = new int*[X_count+2];
	for(int i=0;i<X_count+2;i++){
		cost[i] = new int[X_count+2];
	}

	for(int i=0;i<X_count+2;i++){
		for(int j=i+1;j<X_count+2;j++){
			cost[i][i] = 0;
			cost[i][j] = findcost(i, j);
			cost[j][i] = cost[i][j];
		}
	}

	result = getresult();
	cout << result << "\n";

}
