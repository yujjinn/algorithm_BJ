//2667
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int apart[25][25];
int visited[25][25] = { 0, };
vector<int> rsd;
int cnt = 0; 


typedef struct { int x, y; }Dir;
Dir movD[4]= { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(int a, int b) {
	// recursive
	cnt++;
	int x, y;
	visited[a][b] = true;
	for (int i = 0; i < sizeof(movD); i++) {
		x = a + movD[i].x;
		y = b + movD[i].y;
			if (apart[x][y] == 1 && visited[x][y] == 0) {
				dfs(x,y);
			}
		
	}
}

int main() {

	int n;
	cin >> n ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> apart[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (apart[i][j] == 1 && visited[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				rsd.push_back(cnt);
			}
		cnt = 0; // ÃÊ±âÈ­
	}
	cout << rsd.size() << endl;
	sort(rsd.begin(), rsd.end());
	for (int i = 0; i < rsd.size(); i++)
		cout << rsd[i] << endl;


	return 0;


}
