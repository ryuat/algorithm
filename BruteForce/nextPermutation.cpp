#include <iostream>
#include <vector>


/*
10972 
다음 순열
(next_perm 구현)

*/
using namespace std;

vector<int> a(10000);


bool next_perm(vector<int> &a, int n) {
	/* i 찾기
	   j 찾기
	   swap(a[i-1], a[j])
	   i부터 뒤집기
		*/

	// i찾기: a[i-1] < a[i] 를 만족하는 가장 우측 인덱스
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		i -= 1;
	}
	if (i <= 0) {
		return false; // 그 순열은 마지막 순열. 다음 순열 없음
	}
	
	// j찾기: a[i-1] < a[j] 를 만족하는 가장 우측 인덱스
	int j = n - 1;
	while (a[i - 1] >= a[j]) {
		j -= 1;
	}

	// swap
	swap(a[i - 1], a[j]);

	// i부터 뒤집기
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;


	
}
int main(void) {

	int n;
	cin >> n;
	
	vector<int> a(n);


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (next_perm(a, n)) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}

	cout << "\n";

	return 0;
}