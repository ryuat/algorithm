#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N, n; // N: 원소의 개수, n: 원소, r: 결과값
	cin >> N;

	vector<int> num(N + 1); // num[N]: N번째 수

	for (int i = 1; i <= N; i++) {
		cin >> n;
		num[i] = n;
	}

	vector<int> dp(N + 1); // dp[N]: N번째 수를 끝점으로 하는 수열의 길이(문제 조건을 만족하는)
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) { //시작점이 있는 수열부분을 찾는다. (끝점을 제외한 부분)
			if (num[i] > num[j] && dp[i] < dp[j] + 1) { // 원소의 값이 더 작으면서, dp가 더 크면 새로 저장
				dp[i] = dp[j] + 1;
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;

	return 0;
}