/*
baekjoon 2745 ������ȯ 1
B���� N�� 10�������� ��ȯ
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string s; // string �� ���� �Է�
 	int b; // b����
	cin >> s >> b;
	
	int n = s.size(); // string size, �ڸ���
	int d = 0; // ������ ��ȯ ���

	for (int i = 0; i < n; i++) {
		int x;

		if (s[i] - '0' >= 17) // s[i] = 'A'�� ��� 'A'(65) - '0'(48) = 17. �� 17�̻��̸� A..Z��� �Ǵ�  
			x = s[i] - '7'; // 'A'=>10���� �����ϰ� ���� �ƽ�Ű���� 15�� '7'�� ���ش�.
		else
			x = s[i] - '0'; // �׷��� ���� ���, �׳� '0'(48)�� ���ش�.


		if (i == n - 1) { // ������ �ڸ��� b�� ������ �ʰ� ���ϱ⸸ �� �� ���� ����
			d = d + x; 
			break;
		}

		d = (d + x) * b; // ù°�ڸ� ���� b�� �����Ͽ� ���Ѵ�. ��) 4��° �ڸ��� ��� (d+x)*b*b*b
	}

	cout << d << endl;
	
	return 0;
}