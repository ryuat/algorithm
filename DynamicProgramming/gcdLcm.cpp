/*
baekjoon 2609
최대공약수와 최소공배수
gcd(a,b) = gcd(b,a%b)

   lg = ab
=> l = ab/g
*/
#include <iostream>
#include <string>

using namespace std;


int main(void) {
	
	int a, b, r, ab; // a,b입력, r:나머지

	cin >> a; cin >> b;
	ab = a * b;
	while (b) {
		//cout << a <<", " <<b << endl;
		r = a % b;
		a = b;
		b = r;
	
	}

	cout << a <<endl; // 최대공약수
	cout << ab/a<< endl; // 최소공배수 
	return 0;
}