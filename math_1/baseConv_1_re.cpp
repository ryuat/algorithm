/*
baekjoon 2745 진법변환 1 
간단하게 변경
*/

#include <iostream>
#include <string>
using namespace std;
int main() {
	int ans = 0;
	string s;
	int b;
	cin >> s >> b;

	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') // 0~9 사이의 숫자일 경우 
			s[i] = s[i] - '0'; // '0'의 아스키 값을 뺀다.
		else
			s[i] = s[i] - 'A' + 10; // 'A'~'Z'일 경우

		ans = ans * b + s[i]; // b가 n-1번 곱해지도록
	}
	cout << ans << endl;

	return 0;
}