//9933

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;
vector<string>v;

int solution(){
	string rev;
	if (v.size() <=1)  return 0 ; // 비교 대상이 없을 시에 탈락
	for (int i = 0; i < v.size()-1; i++) {
		rev = v[i];
		reverse(rev.begin(), rev.end());
		for (int j = i+1; j < v.size(); j++) {
			if (rev.compare(v[j])==0) {
				int size = v[j].size();
				cout << size << " " << v[j].at(int(size/2));
				return 0;
			}
		}
	}
	return 0;
}

int main() {
	cin >> N;
	string text;
	for (int i = 0; i < N; i++) {
		cin >> text;
		v.push_back(text);
	}
	
	solution();
}