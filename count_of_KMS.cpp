// 1527

#include<iostream>
#include <math.h>
using namespace std;
int cnt=0;
int N, M;


void print_set(int *set, int n) {

	int num = pow(10, n-1);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (set[i] * num);
		num = int(num / 10);
	}
	if (sum >= M && sum <= N) { ++cnt;  }
	cout << sum << " / " << cnt << endl;

}

int rPerm(int *set, int set_size, int m, int n) {

	if (set_size == n) {
		print_set(set, n);
		return cnt;
	}
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0)set[set_size] = 4;
		else if (i % 2 == 1) set[set_size] = 7;
		//print_set(set, set_size);
		rPerm(set, set_size + 1, m, n);
	}
}


int main() {
	cin >> M >> N;
	int count = 0;
	int max = N;
	while (max > 0) {
		count ++;
		max = int(max / 10);
	}

	int * set = new int[N]();
	for (int i=1; i<=count; i++)rPerm(set, 0, 2,i);

	cout << "result : " << cnt << endl;

}