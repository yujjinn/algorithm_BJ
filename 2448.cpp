// 2448
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>

void star(int n, int x, int y);

using namespace std;
char arr[100][100] = {};

int main() {

	int n;
	int cnt = 0;
	int blank_num = 0; // 중간 공백
	cin >> n; //line
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j <2*n; j++) {
			if (j == 2 * n - 1)
				arr[i][j] = '\0';
			else
				arr[i][j] = ' ';
		}

	}*/

	star(n,n-1,0); //  높이, 맨 위 꼭지점 좌표


	for (int k = 0; k < n; k++) {
		for (int l = 0; l < 2 * n - 1; l++) {
			cout << arr[k][l];
		}
		cout << endl;
	}
	
}


void star(int n, int x, int y) {
	if (n ==3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y+1][x+1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x -1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x+1] = '*';
		arr[y + 2][x +2] = '*';
	}
	else {
		star(n / 2, x, y);
		star(n / 2, x - (n / 2), y + (n / 2));
		star(n / 2, x + (n / 2), y + (n / 2));
	}

}

