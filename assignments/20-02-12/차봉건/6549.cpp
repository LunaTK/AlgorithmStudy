#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){

	while(1){

		int n, elem, j, width;
		long long ret=0, area;
		stack<int> remain;

		vector<int> h;
		cin >> n;
		
		if(n==0){
			break;
		}

		for(int i=0; i<n; i++){
			cin >> elem;
			h.push_back(elem);
		}
		h.push_back(0);
	
		for(int i=0; i<=n; i++){

			while(!remain.empty() && h[remain.top()] >= h[i]){
				j = remain.top();
				remain.pop();

				if(remain.empty()){
					width = i;
				}
				else{
					width = i - remain.top() - 1;
				}
				
				area = (long long)width * (long long)h[j];
				cout << area << endl;
				ret = max(ret, area);
			}

			remain.push(i);
		}

		//cout << "ret: " << ret << endl;
		//cout << "stack size: " << remain.size() << endl;
		//cout << "stack top: " << remain.top() << " " << h[remain.top()] << endl;

		cout << ret << endl;
	}
	

}
