//1764
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�赵 ���� ����� ���
//���� ���� ����� ���
// -> ������ ������ ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�

vector<string> NList;
vector<string> MList;
string name;
int N; // �赵 ���� ����� ��
int M; // ���� ���� ����� ��


void solution() {

	vector<string>ans;
	int count = 0; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (NList[i].compare(MList[j]) == 0) {
				ans.push_back(NList[i]);
				count++;
			}
		}
	}
	cout << count << endl;
	for (int k = 0; k < count ; k++) {
		cout << ans[k] << endl;
	}


}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		NList.push_back(name);
	}
	for (int j = 0; j < M; j++) {
		cin >> name;
		MList.push_back(name);
	}
	solution();
}