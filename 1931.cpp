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
int max_cnt=0; //최대 사용할 수 있는 회의실 수
int n; // 회의의 수

int main() {

	int start, end;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(room(start, end));
	
	
	}
	sort(v.begin(), v.end()); // start시간 별로 오름차순

	for (int i = 0; i < n; i++) {
		solution(i);
	}
	
	cout << max_cnt << endl;

}
void solution_edit() {  // 다른 풀이
	int room = 1;
	int st =0;
	int en = 0;

	for (int i = 0; i < n; i++) {
		int meetingBegin = v[i].end, meetingEnd = v[i].start;

		if (st <= meetingBegin)

		{

			//earliest를 마지막 회의가 끝난 시간 이후로 갱신

			st = meetingBegin;

			room++;

		}
	}
	cout << room << endl;
	max_cnt = max(max_cnt, room);
}

void solution(int x) { // 내 풀이 법
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