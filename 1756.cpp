#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
int result(int D, int N);

vector<int>o,p,r;

int main() {
	int D, N;
	cin >> D >> N; // 오븐 깊이 , 피자 반죽 개수
	result(D, N);
	cout << r[r.size()-1] << endl;

}

int result(int D, int N) {
	for (int depth = 0, i = 0; i < D; i++) { //오븐의 지름
		cin >> depth; o.push_back(depth);
	}
	for (int r = 0, i = 0; i < N; i++) { // 피자의 지름
		cin >> r; p.push_back(r);
	}

	int last = o.size() - 1;

	int cnt = 0;
	while (cnt < N) {
		int s = p[0];
		reverse(p.begin(), p.end());
		p.pop_back();
		reverse(p.begin(), p.end());
		if (o[0] < s) {  return 0; }  // 입구 부터 들어가질 않음
		for (int i = 0; i <= last; i++) {
			if (o[i] < s) {
				last = i-1;
				r.push_back(last + 1);
				break;
			}
			if (i == last) {
				r.push_back(last+1);
				last = i - 1;
				break;
			}
		}
		cnt++;
	}

	return 0;
}
