#include <iostream>

/*
현재 k개, 목표 n개를 만족하는
만족하는 최대 길이 x 찾기
*/

using namespace std;

int k, n;
int a[10000];

bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) { // 현재 갖고 있는 랜선을 x의 길이로 자르고 개수를 합한다.
		cnt += a[i] / x;
	}

	return cnt >= n; // 길이 x로 자른 랜선의 개수 cnt가 n개보다 많을 경우 true
}

int main() {
	scanf("%d %d", &k, &n); // 현재 k개, 목표 n개

	int max_val = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		if (max_val < a[i]) {
			max_val = a[i];
		}
	}

	long long max_length = max_val; // 목표개수가 1개일 경우, 제일 긴 랜선 하나만 있으면 된다.
	long long min_length = 1; // n개를 항상 만들 수 있도록 데이터 입력되므로, 최소 길이는 1이다.
	int ans = -1; // 임의의 최소값
	while (min_length <= max_length) { // 최소길이가 최대길이보다 커지면 종료 
		long long mid = (min_length + max_length) / 2; // 이진 탐색을 위한 중앙값(두 값의 합이 int형 범위를 초과하므로 long long 으로 수정)
		if (check(mid)) { // 길이 mid로 목표개수 n개를 만들 수 있는지 확인
			min_length = mid + 1; // 길이 mid로 잘랐을 때 충분하다면 더 크게 잘라본다.
			if (mid > ans) { // 길이 mid가 지금까지 길이 중 제일 큰 값이라면 결과값을 수정
				ans = mid;
			}
		}
		else {
			max_length = mid - 1; // 길이 mid로 잘랐을 때 부족하다면 더 짧게 잘라본다.
		}
	}

	printf("%d\n", ans);
	return 0;
}