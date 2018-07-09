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
	long long right = 2000000000LL * 30LL;// 30�� ¥�� �ⱸ �� ���� 20����� ž���ϴ� �� �ҿ� �ð�

	while (left <= right) {
		long long mid = (left + right) / 2;
		
		long long start=0, end=m, cnt=0;
		for(int i=1;i<=m;i++){ // mid�п� ž���� ������ ��ȣ ã��
			end += mid / t[i];
			if (mid%t[i] == 0) {
				cnt++;
			}
		}
		start = end - cnt + 1; // mid�п� ž���� ù��° ��ȣ
			
		if (n < start) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else { // ã�Ҵٸ�
			
			for (int i = 1; i <= m; i++) {
				if (mid % t[i] == 0) { // mid�п� i�� �ⱸ�� ž���� ���
				
					if (n == start) { // ž���� ������ ��ȣ�� ������ ��ȣ���
						printf("%d\n", i);
						return 0;
					}
					start++; // ���� ������ ��ȣ
				}
			}
			return 0;
		}
	}

	return 0;
}