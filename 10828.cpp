#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

void solution(int n);
int main() {
	int n;
	cin >> n;
	solution(n);
}

void solution(int n) {

	vector<string> v;
	vector<int> num;
	vector<int> res;
	string str = "";
	//입력
	for (int i = 0; i < n + 1; i++) {
		getline(cin, str);
		v.push_back(str);
	}

	v.erase(v.begin());
	// 해석


	for (int cnt = 0, i = 0; i < v.size(); i++) {
		if (!v[i].find("push")) {
			cnt = 0;
			stringstream ss(v[i]);
			while (ss >> str) {
				if (cnt == 1) {
					num.push_back(stoi(str));
				}
				cnt++;
			}
		}
		else if (!v[i].find("pop")) {
			if (!num.size()) {
				res.push_back(-1);
			}
			else {
				res.push_back(num[num.size() - 1]);
				num.pop_back();
			}
		}
		else if (!v[i].find("size")) {
			//size: 스택에 들어있는 정수의 개수를 출력한다.
			res.push_back(num.size());

		}
		else if (!v[i].find("empty")) {
			//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
			if (!num.size()) {
				res.push_back(1);
			}
			else {
				res.push_back(0);
			}

		}
		else if (!v[i].find("top")) {
			//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (!num.size()) {
				res.push_back(-1);
			}
			else {
				res.push_back(num[num.size() - 1]);
			}
		}
	}

	//결과물 출력
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

}
