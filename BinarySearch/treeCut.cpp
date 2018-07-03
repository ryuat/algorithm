#include <iostream>

int a[1000000];
int n, m;
bool check(long long x) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = a[i] - x;
		if (tmp < 0) tmp = 0;
		
		ans += tmp;
	}
	return ans >= m;
}
int main() {
	scanf("%d %d", &n, &m);
	int max_h = 0;
	int min_h;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > max_h) {
			max_h = a[i];
		}
	}
	min_h = 0;
	max_h -= 1; // 최대높이 -1
	
	int ans = 0;
	while (min_h <= max_h) {
		int mid = (min_h + max_h) / 2;
		if (check(mid)) {
			min_h = mid + 1;
			if (mid > ans) {
				ans = mid;
			}
		}
		else {
			max_h = mid - 1;
		}
	}
		
	printf("%d\n", ans);
	return 0;
}