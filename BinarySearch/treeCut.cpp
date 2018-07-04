#include <iostream>
/* 
2805 ���� �ڸ���
*/
int a[1000000];
int n, m;
bool check(int x) { // x�� ���̷� �߶��� �� ������ �����ϴ��� ����
	long long ans = 0; // 1 < a[i] < 1,000,000  ���� �迭�� ���� int ������ �Ѿ �� �ִ�.
	for (int i = 0; i < n; i++) {
		int tmp = a[i] - x; // ������ x���̷� �߶��� ��
		if (tmp < 0) tmp = 0; // �߸� ���̰� 0���� ���� ��� 0
		
		ans += tmp; // �߸� ������ ��
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
	min_h = 0;  // ���̰� 0�� �� �ּ�, ��� ������ �ϴ� �߶�߸� ��ǥ ���̸� ������ ���
	max_h -= 1;	// �ִ���� -1, ��ǥ���̰� 1�� ���, ���� �� �������� 1��ŭ �۰� �ڸ���.
	
	int ans = 0;				// ���� �����
	while (min_h <= max_h) {	// ����Ž��
		int mid = (min_h + max_h) / 2;
		if (check(mid)) {		// ��ǥ ���̸� ������ ���
			min_h = mid + 1;	// �������� Ž��
			if (mid > ans) {	// �������� �ִ밪���� �� ��� �ִ밪 ����
				ans = mid;
			}
		}
		else {					// ��ǥ ���̸� �������� ���� ��� 
			max_h = mid - 1;	//�������� Ž��
		}
	}
		
	printf("%d\n", ans);
	return 0;
}