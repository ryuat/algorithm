/* gcd ��Ŭ���� ȣ���� ����� */
#include <iostream>

using namespace std;

int main(void) {


	int a, b, r;

	cin >> a; cin >> b;

	while (b) {
		r = a % b;  // ������
		a = b;      // ���� a = b
		b = r;      // ���� b = r
	}

	cout << a;
	return 0;
}