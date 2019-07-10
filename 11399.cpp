#include"pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int atm(); // 11399 
int main() {

	cout << atm();
}

int atm() { // 최솟값을 얻기 위해서는 오름차순으로 정렬 후 그 각각에 걸리는 시간을 계산
	vector<int> v; // 숫자
	int n = 0;  int sum = 0; int result = 0;
	cin >> n; // 입력받을 개수

	for (int k = 0, i = 0; i < n; i++) { // 각각 숫자 입력 받기
		cin >> k; v.push_back(k);
	}

	sort(v.begin(), v.end()); // 오름차순 정렬 
	//cf) 만약 내림차순을 하고 싶다면 rbegin() rend() 대신 입력

	for (auto c : v) {
		sum += c;
		result += sum;
	}

	return result;
}
