#include<iostream>
#include<algorithm>

#define M  5;
#define SM 3;
using namespace std;

int cnt = 9999; //���� ����

// ���� ���� 3kg, 5kg
// ��Ȯ�� ����� �Ұ����� ��� -1 ���

int main() {

	int num = 0;
	cin >> num;

	//5�� ���� ����
	for (int cnt_5 = 0, i = 1; i <= num / 5; i++) {

		int mok = i;
		int nam = num - 5*i;
		
		if (nam != 0) {
			if (nam % 3 == 0) {
				cnt_5 += (nam / 3);
				cnt_5 += mok;
				cnt = min(cnt, cnt_5);
			}
		}
		if (nam == 0) {
			cnt_5 += mok;
			cnt = min(cnt, cnt_5);
		}
		
		cnt_5 = 0;
	}
	// 3���� ����
	for (int cnt_3 = 0, j = 1; j <= num / 3; j++) {
	
		int mok = j;
		int nam = num - 3 * j;
	
		if (nam != 0) {
			if (nam % 5 == 0) {
				cnt_3 += (nam / 5);
				cnt_3 += mok;
				cnt = min(cnt, cnt_3);
			}
		}
		if (nam == 0) {
			cnt_3 += mok;
			cnt = min(cnt, cnt_3);
		}
		
		cnt_3 = 0;
	}
	if (cnt == 9999) { cout  << -1 << endl; }
	else { cout << cnt << endl; }
}
