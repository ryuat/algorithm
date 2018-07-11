#include <iostream>
#include <string>
/*
11723 집합
std::ios_base::sync_with_stdio(false);
를 명시할 경우, cin만 사용한다.


수정 전 입출력 관련 시간초과가 나오는데, 원인은 아직 잘 모르겠다.
*/
using namespace std;


int res;
bool check(int num) {
	int a, b;
	a = res & (1 << num);
	b = (1 << num);

	return a == b;
}
void remove(int num) {
	res = res & ~(1 << num);
}
void add(int num) {
	res = res | (1 << num);
}

int main() {
	std::ios_base::sync_with_stdio(false);


	int n;
	cin >> n;
	res = 0; // 0 0 0 0 0 0 0 0 0 0 0 0 0...

	while (n--) {
		string op;
		cin >> op;
		int num;

		if (op == "add") {
			cin >> num;
			add(num);
			//printf("%d\n", res);
		}
		else if (op == "check") {
			cin >> num;
			if (check(num)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
		}
		else if (op == "remove") {
			int num;
			cin >> num;
			remove(num);
			//printf("%d\n", res);
		}
		else if (op == "toggle") {
			cin >> num;
			if (check(num)) {
				remove(num);
			}
			else {
				add(num);
			}
		}
		else if (op == "all") {
			res = (1 << 21) - 1;
			//printf("%d\n", res);
		}
		else if (op == "empty") {
			res = 0;
		}
	}

	return 0;
}