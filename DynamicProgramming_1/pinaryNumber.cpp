#include <iostream>
#include <vector>
#include <algorithm>

/*
2193
이친수
*/

using namespace std;

long long d[91][2];

int main(void) {
	int n;
	
	scanf("%d", &n);

	d[1][0] = 0;
	d[1][1] = 1;
	
	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	printf("%lld", d[n][0] + d[n][1]);
	
	return 0;
}