/*
baekjoon 2609
�ִ������� �ּҰ����
gcd(a,b) = gcd(b,a%b)

   lg = ab
=> l = ab/g
*/
#include <iostream>
#include <string>

using namespace std;


int main(void) {
	
	int a, b, r, ab; // a,b�Է�, r:������

	cin >> a; cin >> b;
	ab = a * b;
	while (b) {
		//cout << a <<", " <<b << endl;
		r = a % b;
		a = b;
		b = r;
	
	}

	cout << a <<endl; // �ִ�����
	cout << ab/a<< endl; // �ּҰ���� 
	return 0;
}