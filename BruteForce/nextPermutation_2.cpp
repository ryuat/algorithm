#include <iostream>
#include <vector>
#include <algorithm>

/*
10972 
다음 순열
(next_perm 라이브러리 사용) 

*/
using namespace std;

vector<int> a(10000);

int main(void) {

	int n;
	cin >> n;
	
	vector<int> a(n);


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (next_permutation(a.begin(), a.end())) {
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