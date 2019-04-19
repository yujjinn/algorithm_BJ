//1157

#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	int arr[26] = { 0, };// ¾ËÆÄºª °¹¼ö ÀúÀå
	int max_count = 0;
	int idx;
	int count = 0;
	char dum;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {

		int n = word[i];

		if (n < 97) {
			arr[n - 65]++;
		}
		else {
			arr[n - 97]++;
		}
	}


	for (int i = 0; i < 26; i++) {
		if (arr[i] > max_count ) {
			max_count = arr[i];
			idx = i;
		}
	}


	for (int i = 0; i < 26; i++) {
		if (arr[i] == max_count) {
			count++;
			if (count >= 2) { cout << "?" << endl; return 0; }
		}
	}
	cout << (char)(idx + 65) << endl;

}