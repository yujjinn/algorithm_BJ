// 2231
#include <iostream>
using namespace std;

int sum(int n) {

	int sum = n;

	while (n > 0) {
		sum += (n % 10);
		n = int(n / 10);
	}
	return sum;
}


int solution(){

	int answer = 0;
	int x;
	cin >> x;
	for (int i = 0; i < 1000000; i++) {
		if (sum(i) == x)
			return i;
	}
	
}


int main() {
	
	
	cout << solution();
}