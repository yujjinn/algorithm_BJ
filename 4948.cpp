#include"pch.h"
#include<iostream>
#include<vector>
using namespace std;
vector<int > v;

void solution(int n);
int prime(int n);
void getChar(int num);
int main(){;

	int n;
	while (cin >> n) {
		if (n == 0)break;
		v.push_back(n);
	}

	for (auto a : v) { //vector에 담긴 숫자 차례로 진행
		getChar(a);
	}

}

//에라토스테네스의 체
void getChar(int num) {
	int cnt = 0;
	int *arr;
	
	arr = (int*)malloc(sizeof(int)*num*2);  //받은 사이즈만큼 배열을 만듦 -> 시간단축 한 몫 (불필요한 곳까지 갈 필요 없음)
	int i = 2;
	for (i = 2; i <= num*2; i++) { //초기화
		arr[i] = i;
	}
  
	for (int i = 2; i <= num*2; i++) {
		if (arr[i] == 0)continue; //이미 체크된 배수는 확인하지 않음
		for (int j = i*2; j <= num*2; j += i) { //배수인 경우 0으로 만듦
			arr[j] = 0;
		}
	}

	//개수 파악 -> 앞서 배수인 경우는 0으로 저장
	for (int i =num+1; i <= num*2; i++) {
		if (arr[i] != 0)cnt++; //값이 0이 아니라는 뜻은 어떤 수의 배수도 아니라는 뜻
	}
	cout << cnt << "\n"; //결과값 도출
}

