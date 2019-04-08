// 2974
#include "pch.h"
#include <iostream>
using namespace std;

int self(int n) {
	int org = n;
	int sum = 1;
	while (n > 0) { 
		sum *= (n%10);
		n = int(n / 10);
	}
	return sum*org;


}

void dfs(int n, int  m) {

}

int main() {
	
	int x, y, cnt, answer, result;
	cin >> x >> y; // x<= N <= y
	cnt = 1; // 양의 정수 == 자연수
	answer = 0;
	result = x;
	while (cnt <= y) {
		result = self(cnt);
		//cout << cnt << " : "<< result;
		cnt++;
		if ((result >= x) && (result <= y)) {
			answer++;
			//cout << " -> " << endl;
		}

	}

	cout << answer;
	
	return 0;

}