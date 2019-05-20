#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int swap(int i, int j);
int Permutation(int TotalN, int N);
int num_data[100];
vector<string>v;


int swap(int i, int j)
{
	int temp;
	if (i == j) return 0;
	temp = num_data[i];
	num_data[i] = num_data[j];
	num_data[j] = temp;
	return 0;
}

int Permutation(int TotalN, int N)
{
	int i;
	string str;
	if (N == 1) {
		for (i = 0; i < TotalN; i++) {
			str += to_string(num_data[i]);
		}v.push_back(str);
		return 0;
	}

	for (i = 0; i < N; i++) {
		swap(i, N - 1);
		Permutation(TotalN, N - 1);
		swap(i, N - 1);
	}
}


int main()
{
	vector<string>::iterator itr;
	int N;
	cin >> N;
	string str;
	//1~N까지 입력
	for (int i = 0; i < N; i++)
		num_data[i] = i + 1;

	Permutation(N, N);
	sort(v.begin(), v.end());
	int k;
	cin >> k;
	int r;
	if (k == 1) {
		cin >> r;
		r--;
		for (int i = 0; i < v[r].size(); i++) {
		cout << v[r].at(i) << " ";
		}
	}
	else if (k == 2) {
		getline(cin, str);
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		for (int i = 0; i < v.size(); i++) {
			if (!v[i].compare(str)) {
				cout << i+1 << endl;
			}
		}
	}

}
