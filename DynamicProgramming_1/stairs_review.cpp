#include <iostream>

int a[301]; // i번째 
int d[301]; // i번째 계단을 밟을 경우 최대 점수


int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {

	int n;
	scanf("%d", &n);


	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i - 3] + a[i - 1], d[i - 2]) + a[i];
		// i번째를 밟는다고 가정할 때,
		// i번째의 선택에 어느 인덱스까지 종속되는지 생각해야한다.
	}

	printf("%d", d[n]);
}












