#include<iostream>


using namespace std;

// ���� ���̰� ������ �ð��� ���

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
	cin >> time;//�ɸ��� �ð�
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