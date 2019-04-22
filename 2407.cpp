// 2407
#include<iostream>

using namespace std;


double solution(int x, int y) {

	double U = 1;
	double D = 1;
	for (int i = x; i > x - y; i--) {
		U *= i;
	}

	for (int j = y; j > 0; j--) {
		D *= j;
	}
	
	return (double)(U / D);
}


int main() {

	int n, m;
	double  ans = 0;
	cin >> n >> m;
	ans= solution(n, m);
	cout << ans;
}