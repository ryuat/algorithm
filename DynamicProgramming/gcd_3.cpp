/* gcd 유클리드 호제법 비재귀 */
#include <iostream>

using namespace std;

int main(void) {


	int a, b, r;

	cin >> a; cin >> b;

	while (b) {
		r = a % b;  // 나머지
		a = b;      // 다음 a = b
		b = r;      // 다음 b = r
	}

	cout << a;
	return 0;
}