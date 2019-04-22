// 1931
#include<iostream>
#include<algorithm>
#include<vector>

void solution(int x);
void solution_edit();
void copy();
using namespace std;

class room {
public :
	int start;
	int end;
	room(int start, int end) {
		this -> start = start;
		this -> end = end;
	}
	bool operator < (const room &a) const {
		return this->start < a.start;
	}
};

vector<room> v;
int max_cnt=0; //�ִ� ����� �� �ִ� ȸ�ǽ� ��
int n; // ȸ���� ��

int main() {

	int start, end;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(room(start, end));
	
	
	}
	sort(v.begin(), v.end()); // start�ð� ���� ��������

	for (int i = 0; i < n; i++) {
		solution(i);
	}
	
	cout << max_cnt << endl;

}
void solution_edit() {  // �ٸ� Ǯ��
	int room = 1;
	int st =0;
	int en = 0;

	for (int i = 0; i < n; i++) {
		int meetingBegin = v[i].end, meetingEnd = v[i].start;

		if (st <= meetingBegin)

		{

			//earliest�� ������ ȸ�ǰ� ���� �ð� ���ķ� ����

			st = meetingBegin;

			room++;

		}
	}
	cout << room << endl;
	max_cnt = max(max_cnt, room);
}

void solution(int x) { // �� Ǯ�� ��
	int room = 1;
	int st = v[x].start;
	int en = v[x].end;
	
	for (int i = x; i < n; i++) {
		if (v[i].start > en ) {
			room++;
			st = v[i].start;
			en = v[i].end;
		}
	}
	max_cnt = max(max_cnt, room);
}