#include <iostream>

int a[1001]; // i번째 수
int d[1001]; // i번째 수를 마지막으로 하는 감소수열의 최대 길이
int main(void) {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int max = 1; // d[i]의 최소값 1(수열에 자기 자신만 존재)
	
		for (int j = 1; j < i; j++) {

			if (a[j] > a[i]) {
				if (d[j]+1 > max) { // j번째 수를 마지막으로 하는 각 감소수열들에 자신을 붙였을 때 길이 중 최대 길이 찾기
					max = d[j] +1;
				}
			}
		}
		d[i] = max;
	}
	int res =0;
	for (int i = 1; i <= n; i++) {
		if (d[i] > res) {
			res = d[i];
		}
	}
	printf("%d\n", res);
	return 0;
}