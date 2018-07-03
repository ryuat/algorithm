#include <iostream>

/*
���� k��, ��ǥ n���� �����ϴ�
�����ϴ� �ִ� ���� x ã��
*/

using namespace std;

int k, n;
int a[10000];

bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) { // ���� ���� �ִ� ������ x�� ���̷� �ڸ��� ������ ���Ѵ�.
		cnt += a[i] / x;
	}

	return cnt >= n; // ���� x�� �ڸ� ������ ���� cnt�� n������ ���� ��� true
}

int main() {
	scanf("%d %d", &k, &n); // ���� k��, ��ǥ n��

	int max_val = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		if (max_val < a[i]) {
			max_val = a[i];
		}
	}

	long long max_length = max_val; // ��ǥ������ 1���� ���, ���� �� ���� �ϳ��� ������ �ȴ�.
	long long min_length = 1; // n���� �׻� ���� �� �ֵ��� ������ �ԷµǹǷ�, �ּ� ���̴� 1�̴�.
	int ans = -1; // ������ �ּҰ�
	while (min_length <= max_length) { // �ּұ��̰� �ִ���̺��� Ŀ���� ���� 
		long long mid = (min_length + max_length) / 2; // ���� Ž���� ���� �߾Ӱ�(�� ���� ���� int�� ������ �ʰ��ϹǷ� long long ���� ����)
		if (check(mid)) { // ���� mid�� ��ǥ���� n���� ���� �� �ִ��� Ȯ��
			min_length = mid + 1; // ���� mid�� �߶��� �� ����ϴٸ� �� ũ�� �߶󺻴�.
			if (mid > ans) { // ���� mid�� ���ݱ��� ���� �� ���� ū ���̶�� ������� ����
				ans = mid;
			}
		}
		else {
			max_length = mid - 1; // ���� mid�� �߶��� �� �����ϴٸ� �� ª�� �߶󺻴�.
		}
	}

	printf("%d\n", ans);
	return 0;
}