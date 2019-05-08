#include<iostream>


using namespace std;

// 오픈 구이가 끝나는 시각을 계산

int main() {

	int h, m;
	int time;
	cin >> h >> m;
	while (1) {
		if ((h > 0 && h < 23) && (m > 0 && m < 60))break;
		else {
			cout << "input again " << endl;
			cin >> h >> m;
		}
	}
	cin >> time;//걸리는 시간
	m += time;
	
	if (m < 60) {
		cout << h << " " << m << endl;
	}
	else {
		h += int(m / 60);
		m = m % 60;
		cout << h << " " << m << endl;
	}

}