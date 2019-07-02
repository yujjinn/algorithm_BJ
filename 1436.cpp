//dooms day num -> includes 6 in a low at least 3 times!
//in this case , the smallest num is '666'
#include"pch.h"
#include<iostream>
#include<string>
using namespace std;

int solution(int n);

int main() {
	int n;
	cin >> n;
	cout << solution(n);
}
int solution(int n) {
	int result = 666; //결과값
	int cnt = 0; // n번째 확인 값
	string s = "";
	
	while(true){
		s = to_string(result);
		if (s.find("666") != string::npos) { //'666' 포함 되었다면
			cnt++; // 포함된 횟수 확인
			result++; // 이번이 마지막이 아닌 경우를 위해 +1 해줌
			if (cnt == n) return result-1; // 만약 횟수도 똑같고 666도 포함되었다면 break;
		}
		else { //그렇지 않은 경우 +1
			result++;
		}
	}
}
