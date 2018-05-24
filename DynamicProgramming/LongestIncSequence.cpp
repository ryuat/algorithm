#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N, n; // N: ������ ����, n: ����, r: �����
	cin >> N;

	vector<int> num(N + 1); // num[N]: N��° ��

	for (int i = 1; i <= N; i++) {
		cin >> n;
		num[i] = n;
	}

	vector<int> dp(N + 1); // dp[N]: N��° ���� �������� �ϴ� ������ ����(���� ������ �����ϴ�)
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) { //�������� �ִ� �����κ��� ã�´�. (������ ������ �κ�)
			if (num[i] > num[j] && dp[i] < dp[j] + 1) { // ������ ���� �� �����鼭, dp�� �� ũ�� ���� ����
				dp[i] = dp[j] + 1;
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;

	return 0;
}