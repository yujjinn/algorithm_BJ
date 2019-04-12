
//1239
#include <iostream>
#include<vector>
using namespace std;

int cls[8];
int set[8];
int N;
vector<int> v;
int Max;


void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}


int find_max() {
	int end = 0;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		v.push_back(set[i]);
		sum += set[i];
		if (sum == 50 ) {
			cnt++;
			end = i+1;
			for (int j = 0; j < i; j++) {
				if ((end + 1) == N) break;
				if (set[end] == v[j]) { cnt++; }
				end++;
			}
		}
	}
	return cnt;
}

int return_max(int n, int m) {
	if (n > m) {
		return n;
	}
	else { return m; }
}


void permutation(int n, int r)
{
	if (r == 0) {
		Max=  return_max(find_max(), Max);
		v.clear();
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(&cls[i], &cls[n - 1]);
		set[r - 1] = cls[n - 1];
		permutation(n - 1, r - 1);
		swap(&cls[i], &cls[n - 1]);
	}
}

int main(void)
{

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cls[i];
	}
	permutation(N , N);
	cout << Max << endl;
	return 0;
}


