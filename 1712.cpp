//BEP(a.k.a break even point) == 손익분기점
#include"pch.h"
#include<iostream>

using namespace std;

//판매 대수와 상관 없이 A만원의 고정 비용이 지출됨
//노트북 한 대를 생산하는데 가변비용 B만원 지출
//ex) A=1000 B=70 -> 10대 생산 = 1000+70*10 = 1700
int solution();
int main() {
	cout << solution();
}
int solution() {
	int a, b, c; //차례로 고정비용, 가변비용, 노트북가격
	cin >> a >> b >> c;
	if (b >= c) {
		return -1;
	}
	else {
		return a / (c - b) + 1;
	}
}
