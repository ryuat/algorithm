/* 
baekjoon 9613 
GCD 합
*/
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(void) {
	int t, n;
	
	cin >> t;

	while (t--) {
		long long sum = 0;

		cin >> n;
		vector<int> num(n);

		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		// combination(n,2) 모든 경우에 대해 gcd를 구하고 합한다.
		for (int i = 0; i < n-1; i++) { 
			for (int j = i + 1; j < n; j++) {
				sum += gcd(num[i], num[j]);
			}
		}
		cout << sum << endl;
	}
	return 0;
}