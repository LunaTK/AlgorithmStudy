#include <iostream>
#include <vector>

using namespace std;

int max_num = 0;
void left_move(vector<int> board, int N, int execute_num);
void right_move(vector<int> board, int N, int execute_num);
void upper_move(vector<int> board, int N, int execute_num);
void down_move(vector<int> board, int N, int execute_num);

void findmax(vector<int> board, int N){
	int i;
	for(i=0;i<N*N;i++){
		if(board[i] > max_num){
			max_num = board[i];
		}
	}
	return;
}

void printboard(vector<int> board, int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << board[i*N+j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void left_move(vector<int> board, int N, int execute_num){
	int i, j, k, offset, first, second, flag, while_flag;

	for(i=0;i<N;i++){
		flag = 0;
		for(j=0;j<N;j++){
			offset = i*N+j; // offset 0 start
			
			while(board[offset] == 0){
				while_flag = 0;
				for(k=offset+1;k<(i+1)*N;k++){
					if(board[k]!=0){
						while_flag = 1;
					}
				}
				if(while_flag == 0){
					break;
				}
	
				for(k=offset+1;k<(i+1)*N;k++){
					board[k-1] = board[k];
				}
				board[(i+1)*N-1] = 0;	
			}

			if(board[offset] != 0){
				if(flag ==0){
					first = offset;
					flag = 1;
				}
				else{
					second = offset;
					if(board[first] == board[second]){
						board[first] = board[first]*2;
						board[second] = 0;
						flag = 0;
						j--;
						continue;
					}
					else{
						first = second;
					}
				}
			}
		}
	}
	execute_num++;

	if(execute_num!=5){
		right_move(board, N, execute_num);
		upper_move(board, N, execute_num);
		down_move(board, N, execute_num);
	}
	else{
		findmax(board, N);
	}
	//printboard(board,N);
	return;
}

void right_move(vector<int> board, int N, int execute_num){
	int i, j, k, offset, first, second, flag, while_flag;

	for(i=N-1;i>=0;i--){
		flag = 0;
		for(j=N-1;j>=0;j--){
			offset = i*N+j; // offset 8 start
			
			while(board[offset] == 0){
				while_flag = 0;
				for(k=offset-1;k>=i*N;k--){
					if(board[k]!=0){
						while_flag = 1;
					}
				}
				if(while_flag == 0){
					break;
				}
	
				for(k=offset-1;k>=i*N;k--){
					board[k+1] = board[k];
				}
				board[i*N] = 0;
			}

			if(board[offset] != 0){
				if(flag ==0){
					first = offset;
					flag = 1;
				}
				else{
					second = offset;
					if(board[first] == board[second]){
						board[first] = board[first]*2;
						board[second] = 0;
						flag = 0;
						j++;
						continue;
					}
					else{
						first = second;
					}
				}
			}
		}
	}
	execute_num++;

	if(execute_num!=5){
		left_move(board, N, execute_num);
		upper_move(board, N, execute_num);
		down_move(board, N, execute_num);
	}
	else{
		findmax(board, N);
	}
	//printboard(board,N);
	return;

}

void down_move(vector<int> board, int N, int execute_num){
	int i, j, k, offset, first, second, flag, while_flag;

	for(i=N-1;i>=0;i--){
		flag = 0;
		for(j=N-1;j>=0;j--){
			offset = i+j*N; // offset 0 start
			
			while(board[offset] == 0){
				while_flag = 0;
				for(k=offset-N;k>=i;k-=N){
					if(board[k]!=0){
						while_flag = 1;
					}
				}
				if(while_flag == 0){
					break;
				}
	
				for(k=offset-N;k>=i;k-=N){
					board[k+N] = board[k];
				}
				board[i] = 0;	
			}

			if(board[offset] != 0){
				if(flag ==0){
					first = offset;
					flag = 1;
				}
				else{
					second = offset;
					if(board[first] == board[second]){
						board[first] = board[first]*2;
						board[second] = 0;
						flag = 0;
						j++;
						continue;
					}
					else{
						first = second;
					}
				}
			}
		}
	}
	execute_num++;

	if(execute_num!=5){
		left_move(board, N, execute_num);
		right_move(board, N, execute_num);
		upper_move(board, N, execute_num);
	}
	else{
		findmax(board, N);
	}
	//printboard(board,N);
	return;

}

void upper_move(vector<int> board, int N, int execute_num){
	int i, j, k, offset, first, second, flag, while_flag;

	for(i=0;i<N;i++){
		flag = 0;
		for(j=0;j<N;j++){
			offset = i+j*N; // offset 0 start 0,3,6,1,4 ...
			
			while(board[offset] == 0){
				while_flag = 0;
				for(k=offset+N;k<=i+(N-1)*N;k+=N){
					if(board[k]!=0){
						while_flag = 1;
					}
				}
				if(while_flag == 0){
					break;
				}
	
				for(k=offset+N;k<=i+(N-1)*N;k+=N){
					board[k-N] = board[k];
				}
				board[i+(N-1)*N] = 0;	
			}

			if(board[offset] != 0){
				if(flag ==0){
					first = offset;
					flag = 1;
				}
				else{
					second = offset;
					if(board[first] == board[second]){
						board[first] = board[first]*2;
						board[second] = 0;
						flag = 0;
						j--;
						continue;
					}
					else{
						first = second;
					}
				}
			}
		}
	}
	execute_num++;

	if(execute_num!=5){
		left_move(board, N, execute_num);
		right_move(board, N, execute_num);
		down_move(board, N, execute_num);
	}
	else{
		findmax(board, N);	
	}
	//printboard(board, N);
	return;

}

int main(){

	int N, i, j, board_num;
	vector<int> board;	

	cin >> N;
	for(i=0;i<N*N;i++){
		cin >> board_num;
		board.push_back(board_num);
	}

	left_move(board, N, 0);
	right_move(board, N, 0);
	upper_move(board, N, 0);
	down_move(board, N, 0);

	cout << max_num;
	
	return 0;
}
