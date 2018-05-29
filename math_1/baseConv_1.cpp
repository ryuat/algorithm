/*
baekjoon 2745 진법변환 1
B진수 N을 10진법으로 변환
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string s; // string 형 숫자 입력
 	int b; // b진법
	cin >> s >> b;
	
	int n = s.size(); // string size, 자리수
	int d = 0; // 십진법 변환 결과

	for (int i = 0; i < n; i++) {
		int x;

		if (s[i] - '0' >= 17) // s[i] = 'A'일 경우 'A'(65) - '0'(48) = 17. 즉 17이상이면 A..Z라고 판단  
			x = s[i] - '7'; // 'A'=>10으로 매핑하게 위해 아스키값이 15인 '7'을 빼준다.
		else
			x = s[i] - '0'; // 그렇지 않은 경우, 그냥 '0'(48)을 빼준다.


		if (i == n - 1) { // 마지막 자리는 b를 곱하지 않고 더하기만 한 후 루프 종료
			d = d + x; 
			break;
		}

		d = (d + x) * b; // 첫째자리 부터 b를 누적하여 곱한다. 예) 4번째 자리일 경우 (d+x)*b*b*b
	}

	cout << d << endl;
	
	return 0;
}