/*
baekjoon 2745 ������ȯ 1 
�����ϰ� ����
*/

#include <iostream>
#include <string>
using namespace std;
int main() {
	int ans = 0;
	string s;
	int b;
	cin >> s >> b;

	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') // 0~9 ������ ������ ��� 
			s[i] = s[i] - '0'; // '0'�� �ƽ�Ű ���� ����.
		else
			s[i] = s[i] - 'A' + 10; // 'A'~'Z'�� ���

		ans = ans * b + s[i]; // b�� n-1�� ����������
	}
	cout << ans << endl;

	return 0;
}