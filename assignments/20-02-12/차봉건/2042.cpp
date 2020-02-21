#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int index, int start, int end){
	if(start == end){
		tree[index] = a[start];
		return tree[index];
	}
	else{
		tree[index] = init(a, tree, index*2, start, (start+end)/2) + init(a, tree, index*2+1, (start+end)/2+1, end);	
		return tree[index];
	}
}

void update(vector<long long> &tree, int index, int start, int end, int diff_index, long long diff){
	if(diff_index < start || end < diff_index){
		return;
	}
	else{
		tree[index] += diff;
		
		if(start!=end){
			update(tree, index*2, start, (start+end)/2, diff_index, diff);
			update(tree, index*2+1, (start+end)/2+1, end, diff_index, diff);
		}
		return;
	}
}

long long sum_tree(vector<long long> &tree, int index, int start, int end, int sum_start, int sum_end){
	if(sum_end < start || end < sum_start){
		return 0;
	}
	if(sum_start <= start && end <= sum_end){
		return tree[index];
	}

	return sum_tree(tree, index*2, start, (start+end)/2, sum_start, sum_end) + sum_tree(tree, index*2+1, (start+end)/2+1, end, sum_start, sum_end);

}

int main(){

	int N, M, K, h, size, elem, a, b, c, diff;
	cin >> N >> M >> K;
	
	h = (int)ceil(log2(N));
	size = 1 << (h+1);

	vector<long long> A(N);
	vector<long long> tree(size);

	for(int i=0; i<N; i++){
		cin >> elem;
		A[i] = elem;
	}

	init(A, tree, 1, 0, N-1);

	for(int i=0; i<M+K; i++){
		cin >> a >> b >> c;
		if(a == 1){
			diff = c - A[b-1];
			A[b-1] = c;
			update(tree, 1, 0, N-1, b-1, diff);	
		}
		else if(a == 2){
			cout << sum_tree(tree, 1, 0, N-1, b-1, c-1) << endl;
		}

	}

	return 0;
}
