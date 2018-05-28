/* gcd 유클리드 호제법 재귀 */
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main(void) {

	int a, b;

	cin >> a; cin >> b;

	cout << gcd(a,b);
	return 0;
}