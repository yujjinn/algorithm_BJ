// 1012

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int>num;
vector <int>result;


int grd[50][50] = { 0, }; // 땅 좌표
int visited[50][50] = { 0, }; // 방문 여부
int cnt = 0;

// 1 : exist 
// 0 : not exist

typedef struct { int x, y; }Dir;
Dir loc[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // 4변



void dfs(int y, int x) {

	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + loc[i].y;
		int nx = x + loc[i].x;

		
		if (grd[ny][nx] && !visited[ny][nx]) {
			//visited[ny][nx]++;
			dfs(ny, nx);
		}
	}
}


int main() {
	int T, m, n, k;
	int x, y;
	cin >> T;
	int count=0;

	for (int i = 0; i < T; i++) {
		cin >> m >> n >> k; // 가로 m 세로 n 받음(n,m)
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			grd[y][x] = 1;
		}

		for (int i = 0; i < n; i++) { // 출력
			for (int j = 0; j < m; j++) {
				if (grd[i][j] == 1 && visited[i][j] == 0) {
					cnt = 0;
					dfs(i, j);
					num.push_back(cnt);
				}
			}
			
		}
		
		result.push_back(num.size());

		num.clear(); // vector 전부 지우기
	}


	for (int i=0; i<result.size(); i++)
		cout  << " " << result[i] << endl;
	


}