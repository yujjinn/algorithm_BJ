//10250
#include<iostream>
#include<vector>

void solution(int num);
using namespace std;
int n;

vector<int> res;

typedef struct {
	int  h, w, n;
}v;

v TEST[5];

int main() {

	cin >> n;
	int height, room, num;
	for (int i = 0; i < n; i++) {
		cin >> height >> room >> num;
		TEST[i].h = height;TEST[i].w = room;TEST[i].n = num;
	}

	/*for (int k = 0; k < n; k++) {
		solution(k);
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}*/

	for (int j = 0; j < n; j++) {
		int num = 100; // ����
		int room = 0;
		num = num * (TEST[j].n % TEST[j].h) ;;
		room = (int)(TEST[j].n / TEST[j].h)+1;
		cout << num +room << endl;
	}

}

void solution(int num) {

	int room_num = 1;
	int height_cnt = 0;
	for (int i = 1; i <= TEST[num].n; i++) {
		if (i>1 && (i % TEST[num].h) == 1) {
			height_cnt = 0; // �ٽ� 1������ ��
			room_num += 1; // ȣ�� ����
		}
		height_cnt += 100;
	}
	res.push_back(room_num + height_cnt);
}