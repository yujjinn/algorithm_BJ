
//1019
#include <iostream>
using namespace std;
int page[10];//0~9���� ����

void overTen(int n) {

	int i = 0;
	while (n > 0) {

		i = n % 10;
		page[i]++;
		n = int(n / 10);
	}
}


void solution(int n) {

	page[10] = { 0, }; // ù ���ۿ��� �ʱ�ȭ

	for(int i=1; i<=n; i++){
		if (i < 10) { page[i]++; } // 1~9������ �״�� ����
		else { // 10�� ����
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
