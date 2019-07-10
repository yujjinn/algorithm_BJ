#include"pch.h"
#include<iostream>

using namespace std;

int mod = 10007; // 나눌 수 
int solution(int n);
int main() {
	int n;
	cin >> n; // 자리수 입력
	cout << solution(n);
}

// dynamic programming
int solution(int n) {

	int result = 0;
	//2차원 배열 선언 -> 개수 설정
	int arr[1001][10] = { 0, };
	//---자리수,1의자리수
	for (int i = 0; i < 10; i++) { // 1의 자리인 경우 1로 초기화
		arr[1][i] = 1;
	} // 1의 자리수인 경우 모은 경우가 오르막 수이기에


	//2의 자리수부터 ~
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {

			for (int k = j; k < 10; k++)
			{
				arr[i][j] += arr[i - 1][k];
				arr[i][j] %= mod;
			}
			//cout << i << ", " << j << " " << arr[i][j] << "\n";
		}
	}

	for (int i = 0; i < 10; i++) {
		result += arr[n][i];
	}

	return result;
}
