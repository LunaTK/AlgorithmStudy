#include<iostream>


using namespace std;

int n, m;
char a[20000002];
int b[500000];
int result[500000];
int x;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x >= 0)a[x] = 1;
		else a[x + 20000001] = '1';
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		if (b[i]>=0&&a[b[i]]==1) {
			result[i] = 1;
		}
		else if (a[b[i] + 20000001] == 1) {
			result[i] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << result[i] << " ";
	}
	cout << endl;

}
