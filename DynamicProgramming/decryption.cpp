/*
baekjoon 2011 암호해석
d[i] : 1~i번째 자리를 하나의 숫자로 볼 때 암호해석이 가능한 경우의 수
*/

#include <iostream>
#include <string>

using namespace std;

int d[5001];
int mod = 1000000;

int main(void) {
	
	string s;
	cin >> s;

	int n;
	n = s.size();
	
	s = " " + s;

	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0'; // 스트링에서 한 자리 0:48, 1 : 49 ..

		if (1 <= x && x <= 9) {  // 10, 20의 경우 일의자리가 0이 올 경우, 일의 자리 한 자리로 암호를 만들 수 없음
			d[i] = d[i - 1] % mod;
		}

		if (i == 1 || s[i - 1] == '0'); // 스트링의 첫 번째자리의 경우 두 자리의 숫자 암호로 해석할 수 없음
										//기준자리 좌측 숫자가 0일 경우 두 자리의 숫자 암호로 해석할 수 없음

		x = (s[i - 1] - '0') * 10 + (s[i] - '0');

		if (10<= x && x <= 26){
			d[i] += d[i - 2] % mod;
			d[i] %= mod;
		}
	}

	cout << d[n] << endl;

	return 0;
}