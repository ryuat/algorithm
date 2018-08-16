/*
9465 
스티커
*/

#include <iostream>
int a[3][100001]; // a[n][m]: n행 m열의 점수
int d[100001][3]; // d[n][m]: n열길이의 스티커 중 m번째(0: 선택안함) 스티커를 선택할 경우 최대점수

int max(int val1, int val2) {
	return (val1 >= val2) ? val1 : val2;
}
int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
	
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		d[0][0] = 0;
		d[0][1] = 0;
		d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);  // i번 선택x -> i-1번째 모든 경우 가능
			d[i][1] = max(d[i - 1][0], d[i-1][2]) + a[1][i]; // i번째 1번 스티커 선택 -> i-1번째 선택 x, i-1번째 2번 스티커
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[2][i];

		}

		int result = max(max(d[n][0], d[n][1]), d[n][2]);
		printf("%d\n", result);
	}
	
	return 0;
}