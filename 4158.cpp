#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>n,m;
vector<int>::iterator iter;

int main() {

	int N, M;//상근이 N 선영이 M 
	int num =0;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		n.push_back(num);
	}
	for (int j = 0; j < M; j++) {
		cin >> num;
		m.push_back(num);
	}
	cout << 0 << " " << 0 << endl;
	// 입력 완료

	if (n.size() < m.size()) {
		for (int k = 0; k < n.size(); k++) {
			iter = find(m.begin(), m.end(), n[k]);
			if (iter != m.end()) cnt++;
		}
	}
	else {
		for (int k = 0; k < m.size(); k++) {
			iter = find(n.begin(), n.end(), m[k]);
			if (iter != n.end()) cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}