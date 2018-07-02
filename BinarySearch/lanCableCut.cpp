#include <iostream>
/*
1654
랜선 자르기
(수정 중)

*/

/*
1부터 최대길이로 다 잘라보고 n개 이상 나오는 최대값을 찾는다.
(n개 이상 만드는 최대길이)
*/

using namespace std;


long long a[10000]; // 현재 랜선 개수 k개 최대값은 10000
int k, n;

bool check(long long m) { // 길이 m으로 n개를 만들 수 있을까?
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] / m; // 각 랜선으로 만들 수 있는 랜선수의 합
	}
	return sum >= n;
}

int main() {
	cin >> k >> n;
	long long max_len = 0;
	for (int i = 0; i < k; i++) {// 현재 개수만큼 
		scanf("%lld", &a[i]);
		if (max_len < a[i]) {
			max_len = a[i];
		}
	}

	long long min_len = 1;
	long long ans = 0;
	while (min_len <= max_len) { // min_len가 max_len보다 작거나 같으면
		long long mid = (max_len + min_len) / 2;
		if (check(mid)) { // mid 길이로 n개를 만들 수 있다면
			min_len = mid + 1;// 더 크게
			if (ans < mid) {
				ans = mid;
			}
		}
		else { // mid 길이로 n개를 만들 수 없다면
			max_len = mid - 1; // 더 작게
		}
	}

	printf("%lld\n", ans);
	return 0;
}
