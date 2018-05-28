/* 
baekjoon 1934 최소공배수 
lcm = a*b/gcd
*/
#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(void) {

	int n;
	cin >> n;
	while (n--) {
		int a, b, g;
		cin >> a; cin >> b;
		
		g = gcd(a, b);

		cout << a*b/ g << endl;
	}
	return 0;
}