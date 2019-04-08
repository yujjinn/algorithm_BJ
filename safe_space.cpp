// 2468

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int>num; 
vector<int>cnt_area;
vector<int>result;
int area[100][100];
int visited[100][100] = {0,};
int max = 0; // 안전 영역 최대 개수 구하는 변수
int cnt = 0; // 개수 구하는 변수



typedef struct {
	int x, y;
}Dir;
Dir movD[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };



void dfs(int x, int y, int n) {

	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + movD[i].x;
		int ny = x + movD[i].y;

		if (area[nx][ny] <= n && !visited[nx][ny])
			dfs(nx, ny, n);

	}

}

int main() {

	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) { // 배열 초기화
		for (int j = 0; j < N; j++) { cin >> area[i][j]; }
	}


	/*------------------vector 정리-----------------*/
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			num.push_back(area[i][j]);
			count++;
		}
	}

	sort(num.begin(), num.end());  // 오름차순 정렬, 중복 값 제거
	for (unsigned i = 0; i < num.size()-1; i++) {
		if (num[i] == num[i + 1]) {
			num.erase(num.begin() + (i + 1));
			i--;
		}
	}
	/*------------------vector 정리-----------------*/

	
	for (int n = 0; n < num.size(); n++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((area[i][j] <= num[n]) && (visited[i][j]==0)) {
					dfs(i, j, num[n]);
					cnt_area.push_back(cnt);
				}
				cnt = 0;//초기화
			}
		}
		result.push_back(cnt_area.size());
		cnt_area.clear();
	}

	sort(result.begin(), result.end());
	cout <<  result[result.size()-1];


}