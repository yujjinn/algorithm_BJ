// 2966
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//상근이는 A, B, C, A, B, C, A, B, C, A, B, C, .
//창영이는 B, A, B, C, B, A, B, C, B, A, B, C, ...
//현진이는 C, C, A, A, B, B, C, C, A, A, B, B, ...
//  


char dummy[100];
char answer[100];
vector<char>ans;
string name[3] = { "Adrian","Bruno","Goran"};

int cnt(int n) {

	int count = 0;
	answer[0];
	for (int i = 0; i < n; i++) {
		if (answer[i] == ans[i])count++;
	}
	return count;
}

int find_max(int n, int max) {

	if (n > max) { max = n;  return max; }
	else return max;
}



void solution(int n){
	
	int max=0;
	int count = 0;
	int find_name, find_name_max ;
	for (int i = 0; i < n; i++)  // Adrian
	{
		//find_name=0;
		if ((i % 3) == 0) ans.push_back('A');
		else if ((i % 3) == 1) ans.push_back('B');
		else if ((i % 3) == 2) ans.push_back('C');
	}
	max = cnt(n); find_name_max = 0;
	ans.clear();
	for (int i = 0; i < n; i++)  // Bruno
	{
		//find_name=1;
		if ((i % 4) == 0) ans.push_back('B');
		else if ((i % 4) == 1) ans.push_back('A');
		else if ((i % 4) == 2) ans.push_back('B');
		else if ((i % 4) == 3) ans.push_back('C');
	}

	if (cnt(n) > max) find_name_max = 1;
	max = find_max(cnt(n),max);
	ans.clear();
	for (int i = 0; i < n; i++)  // Goran
	{
		//find_name=2;
		if ((i % 6) == 0) ans.push_back('C');
		else if ((i % 6) == 1) ans.push_back('C');
		else if ((i % 6) == 2) ans.push_back('A');
		else if ((i % 6) == 3) ans.push_back('A');
		else if ((i % 6) == 4) ans.push_back('B');
		else if ((i % 6) == 5) ans.push_back('B');

	}
	if (cnt(n) > max) find_name_max = 2;
	max = find_max(cnt(n), max);
	cout << max << endl;
	for(int i=0; i<sizeof(name); i++)if (find_name_max == i)  cout << name[i]; 
	

}


int main(){
	
	int x;

	cin >> x; // 맞추고자 하는 정답 개수
	for (int i = 0; i < x+1; i++) dummy[i] = cin.get(); // enter까지 저장
	for (int i = 0; i < x; i++) answer[i] = dummy[i + 1];
	solution(x);
}