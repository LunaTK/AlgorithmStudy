#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct EDGE {
	int a, b, c;
}edge;

int n, m;
vector <edge> v;

int arr[10001]={ 0, };

bool cmp(const edge &e1, const edge &e2) {
		return e1.c < e2.c;
	
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < m;i++) {

		int a, b, c;
		cin >> a >> b >> c;
		edge e;
		e.a = a;
		e.b = b;
		e.c = c;
		v.push_back(e);
	}
	sort(v.begin(), v.end(), cmp);
	int gid = 0;
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (arr[v[i].a] == 0 && arr[v[i].b] == 0) {
			gid++;
			arr[v[i].a] = gid;
			arr[v[i].b] = gid;
			result += v[i].c;
		}
		else if (arr[v[i].a] != arr[v[i].b]) {
			arr[v[i].a] = gid;
			arr[v[i].b] = gid;
			result += v[i].c;
		}
		else if (arr[v[i].a] != 0 && arr[v[i].a] == arr[v[i].b]) {
			continue;
		}

	}
	cout << result << endl;

	return 0;
}
