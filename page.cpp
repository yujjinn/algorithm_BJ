
//1019
#include <iostream>
using namespace std;
int page[10];//0~9까지 저장

void overTen(int n) {

	int i = 0;
	while (n > 0) {

		i = n % 10;
		page[i]++;
		n = int(n / 10);
	}
}


void solution(int n) {

	page[10] = { 0, }; // 첫 시작에는 초기화

	for(int i=1; i<=n; i++){
		if (i < 10) { page[i]++; } // 1~9까지는 그대로 저장
		else { // 10을 넘음
			overTen(i);
		}
	}

	for (int j = 0; j < 10; j++) {
		cout << page[j] << " ";
	}

}


int main() {

	solution(11);

}
