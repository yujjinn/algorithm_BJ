//1764
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//듣도 못한 사람의 명단
//보도 못한 사람의 명단
// -> 듣지도 보지도 못한 사람의 명단을 구하는 프로그램을 작성하시오

vector<string> NList;
vector<string> MList;
string name;
int N; // 듣도 못한 사람의 수
int M; // 보도 못한 사람의 수


void solution() {

	vector<string>ans;
	int count = 0; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (NList[i].compare(MList[j]) == 0) {
				ans.push_back(NList[i]);
				count++;
			}
		}
	}
	cout << count << endl;
	for (int k = 0; k < count ; k++) {
		cout << ans[k] << endl;
	}


}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		NList.push_back(name);
	}
	for (int j = 0; j < M; j++) {
		cin >> name;
		MList.push_back(name);
	}
	solution();
}