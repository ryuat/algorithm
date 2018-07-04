#include <iostream>
/* 
2805 나무 자르기
*/
int a[1000000];
int n, m;
bool check(int x) { // x의 길이로 잘랐을 때 조건을 충족하는지 여부
	long long ans = 0; // 1 < a[i] < 1,000,000  따라서 배열의 합이 int 범위를 넘어설 수 있다.
	for (int i = 0; i < n; i++) {
		int tmp = a[i] - x; // 나무를 x높이로 잘랐을 때
		if (tmp < 0) tmp = 0; // 잘린 길이가 0보다 작을 경우 0
		
		ans += tmp; // 잘린 길이의 합
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
	min_h = 0;  // 높이가 0일 때 최소, 모든 나무를 싹다 잘라야만 목표 길이를 충족할 경우
	max_h -= 1;	// 최대높이 -1, 목표길이가 1일 경우, 제일 긴 나무보다 1만큼 작게 자른다.
	
	int ans = 0;				// 최종 결과값
	while (min_h <= max_h) {	// 이진탐색
		int mid = (min_h + max_h) / 2;
		if (check(mid)) {		// 목표 길이를 충족할 경우
			min_h = mid + 1;	// 우측에서 탐색
			if (mid > ans) {	// 이전까지 최대값보다 길 경우 최대값 수정
				ans = mid;
			}
		}
		else {					// 목표 길이를 충족하지 못할 경우 
			max_h = mid - 1;	//좌측에서 탐색
		}
	}
		
	printf("%d\n", ans);
	return 0;
}