#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;

vector<int>v;
int solution();
int find(int n);
int main() {

	int n, k;
	cin >> n; // n개의 개수만큼 숫자 입력
	for (int i = 0; i < n; i++) {
		cin >> k; 
		v.push_back(k);
	}
	cout << solution(); 

}


int solution() {
	int cnt = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i]))cnt++; //find()함수가 0이 아니라면(소수라면) 개수 증가
	}
	return cnt;
}


int  find(int n) {

	int *arr;
	arr = (int*)malloc(sizeof(int)*n); //vector에 존재하는 숫자만큼 배열 생성
	for (int i = 2; i <= n; i++) { //배열 초기화
		arr[i] = i;
	}
	arr[1] = 0; //1은 소수가 아님
	for (int i = 2; i <= n ; i++) { 
		if (arr[i] == 0) continue; // 자기 자신이 0인 경우 스킵
		for (int j = i * 2; j <= n ; j += i) { // 본인 배수마다 찾음
			arr[j] = 0;
		}
	}


	if (arr[n] != 0) return 1;  // 어느 배수에도 해당안되면 1 return 즉, 소수인경우
	else  return 0; // 어느 숫자의 배수인 경우 0 return 즉, 소수가 아닌 경우
}


