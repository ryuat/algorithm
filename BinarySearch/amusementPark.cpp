#include <iostream>

using namespace std;

int n, m;
int t[10001];

int main(void) {
	scanf("%d %d", &n, &m);

	for(int i=1;i<=m;i++) {
		scanf("%d", &t[i]);
	}

	long long left = 0;
	long long right = 2000000000LL * 30LL;// 30분 짜리 기구 한 개를 20억명이 탑승하는 데 소요 시간

	while (left <= right) {
		long long mid = (left + right) / 2;
		
		long long start=0, end=m, cnt=0;
		for(int i=1;i<=m;i++){ // mid분에 탑승한 마지막 번호 찾기
			end += mid / t[i];
			if (mid%t[i] == 0) {
				cnt++;
			}
		}
		start = end - cnt + 1; // mid분에 탑승한 첫번째 번호
			
		if (n < start) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else { // 찾았다면
			
			for (int i = 1; i <= m; i++) {
				if (mid % t[i] == 0) { // mid분에 i번 기구를 탑승한 경우
				
					if (n == start) { // 탑승한 아이의 번호가 마지막 번호라면
						printf("%d\n", i);
						return 0;
					}
					start++; // 다음 아이의 번호
				}
			}
			return 0;
		}
	}

	return 0;
}