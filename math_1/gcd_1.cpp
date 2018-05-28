#include <iostream>

using namespace std;

int min(int val1, int val2) {
	return (val1 < val2) ? val1 : val1;
}

int main(void) {


	int a, b, gcd;

	cin >> a; cin >> b;

	for (int i = 1; i <= min(a, b); i++) {
		if (a%i == 0 && b%i == 0)
			gcd = i;
	}

	cout << gcd;
	return 0;

}