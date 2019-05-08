#include<iostream>

using namespace std;

int main() {

	int num = 0;
	int five=0,three=0;
	cin >> num;// 숫자 입력 받기
	five = num / 5;
	num = num % 5;
	while (five >= 0) {
		if (num % 3 == 0) {
			three = num / 3;
			num %= 3;
			break;
		}
		five--; num += 5;
	}
	if (num == 0) cout << five + three << endl;
	else cout << -1 << endl;
}
