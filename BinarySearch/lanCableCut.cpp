#include <iostream>
/*
1654
���� �ڸ���
(���� ��)

*/

/*
1���� �ִ���̷� �� �߶󺸰� n�� �̻� ������ �ִ밪�� ã�´�.
(n�� �̻� ����� �ִ����)
*/

using namespace std;


long long a[10000]; // ���� ���� ���� k�� �ִ밪�� 10000
int k, n;

bool check(long long m) { // ���� m���� n���� ���� �� ������?
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] / m; // �� �������� ���� �� �ִ� �������� ��
	}
	return sum >= n;
}

int main() {
	cin >> k >> n;
	long long max_len = 0;
	for (int i = 0; i < k; i++) {// ���� ������ŭ 
		scanf("%lld", &a[i]);
		if (max_len < a[i]) {
			max_len = a[i];
		}
	}

	long long min_len = 1;
	long long ans = 0;
	while (min_len <= max_len) { // min_len�� max_len���� �۰ų� ������
		long long mid = (max_len + min_len) / 2;
		if (check(mid)) { // mid ���̷� n���� ���� �� �ִٸ�
			min_len = mid + 1;// �� ũ��
			if (ans < mid) {
				ans = mid;
			}
		}
		else { // mid ���̷� n���� ���� �� ���ٸ�
			max_len = mid - 1; // �� �۰�
		}
	}

	printf("%lld\n", ans);
	return 0;
}
