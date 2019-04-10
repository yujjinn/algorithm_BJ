//17136
#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct {
	int x, y;
}Dir;

Dir moveD[2] = {{0,1},{1,0}}; //방향
vector<pair<int, int>> v; // 시발점과 끝점 저장


int min; // 색종이 붙이는데 필요한 갯수
int cnt = 0;
int answer = 0;
int num_paper[5] = { 5,5,5,5,5 };
int visited[10][10] = { 0, };//방문 여부 확인
int paper[10][10] = { 0, };


bool compare(const pair<int, int>&a, const pair<int, int>&b) {

	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;

}

void solution(int n, int m ) {

	visited[n][m] = 1; //방문 했음으로 1 저장
	cnt++;
	cout << "org" << n << "," << m << endl;
	for (int i = 0; i < 2; i++) {
		int nx = n + moveD[i].x;
		int ny = m + moveD[i].y;
		cout << "new " << nx << "," << ny << endl;
		if (paper[nx][ny] == 1 && visited[nx][ny] == 0) {
			v.push_back(make_pair(nx, ny));
			solution(nx, ny);
		}
	}
}
int absolute(int n, int m) {
	if (n < m) { return m - n; }
	else { return n - m; }
}
void find_size() {

	if (cnt == 1) {
		answer += num_paper[0];
		num_paper[0]--;
	}

}
int main() {

//개수 넘어가면 -1출력
	for (int i = 0; i < 10; i++) { // 값 초기화
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < 10; i++) { // 값 초기화
		for (int j = 0; j < 10; j++) {
			if (paper[i][j] == 1 && visited[i][j] == 0) {
				v.push_back(make_pair(i, j));
				solution(i,j);
				sort(v.begin(), v.end(), compare);
				for (int i = 0; i < v.size(); i++) {
					cout << i << "번째 " <<v[i].first << " " << v[i].second << " / cnt : " <<cnt << endl;
				}
				
				if (cnt > 1 && cnt <= 5) {
					cout << v[0].first << "," <<  v[v.size() - 1].first << " /" << v[0].second << ", " << v[v.size() - 1].second << " " << endl;
					if ((absolute(v[0].first, v[v.size() - 1].first) == cnt) && (absolute(v[0].second, v[v.size() - 1].second) == cnt-1)) {
						cout << "same" << endl;
					}
				}
			}
			cnt = 0; v.clear();
		}
	}
	

}