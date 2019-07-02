//아스키 코드로 '0'이 10진수로 48이다 
//참고로 'a' = 97 'A' = 65
#include"pch.h"
#include<iostream>
#include<string>
using namespace std;

char arr[100] = { 0, };
int solution(int n, string s);
int main() {

	int n;
	string s;
	cin >> n;
	while (cin >> s) { // n자리만큼 입력하지 못하면 다시 입력하게끔 제작
		if (s.length() != n) {
			cout << "input length 'n'" << "\n";
		}
		else {
			break;
		}
	}
	cout << solution(n, s);
}
int solution(int n, string s) {
	int cnt = 0;

	strcpy_s(arr, s.c_str()); //string -> char형태로 바꿈

	for (int i = 0; i < s.length(); i++) { // strging 길이만큼 for문 돌림
		cnt += (arr[i]-48); //48을 빼는 이유는 char != int 즉, '0'은 48이고 char에서 int값을 빼면 int값이 나오는 성질 이용
		
	}
	return cnt; 
}
