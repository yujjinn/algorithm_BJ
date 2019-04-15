// 1759
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define swap(a, b, temp) temp=a; a=b; b=temp;
using namespace std;

char arr[16];
char dummy[16];
set <char> moeum_set({ 'a','e','i','o','u' }); // 모음 최소 1개
int cnt = 0;
int L, C;

int dec() {
	int c = 0;
	int m = 0;
	for (int i = 0; i < L; i++) {
		if (moeum_set.find(dummy[i]) == moeum_set.end()) c++;
		else m++;
	}
	//cout << "M " << c << " , " << "J " << m << endl;
	if (c>=2 &&m>=1) return true;
	else return false;
}

void solution(int n, int r) {
	if (r == 0) {
		if (dec() == true) {
			for (int i = 0; i < L; i++) {
				cout << dummy[i];
			}
			cout << endl;
			cnt++;
		}
	}
	else if (n < r) return;
	else {
		dummy[r - 1] = arr[n - 1];
		solution(n - 1, r - 1);
		solution(n - 1, r);
	}
}
int main() {
	// L,C 정수
	cin >> L >> C;

	for (int i = 0; i < C; i++) { cin >> arr[i]; }
	sort(arr, arr + C);
	
	solution(C, L);

	//cout << "cnt " << cnt << endl;
	return 0;
}
