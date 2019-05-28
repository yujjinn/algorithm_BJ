#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct {
	int e, a, b;
}M;

M arr[100000];

int main() {
	int n, m;
	vector<int>a, b, s;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i].e >> arr[i].a >> arr[i].b;
	}
	for (int i = 0; i < m; i++) {

		if (arr[i].e == 0) { //합집합
			if (find(a.begin(),a.end(),arr[i].b) != a.end()) {
				s.push_back(arr[i].b);
			}
			if (find(b.begin(), b.end(), arr[i].a) != b.end()) {
				s.push_back(arr[i].a);
			}
			if ((find(b.begin(), b.end(), arr[i].a) == b.end()) &&(find(b.begin(), b.end(), arr[i].a) == b.end())) {
				a.push_back(arr[i].a);
				b.push_back(arr[i].b);
			}
		}
		else if (arr[i].e == 1) {
			if((find(s.begin(), s.end(), arr[i].b) != s.end()) && (find(s.begin(), s.end(), arr[i].a) != s.end())) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}
