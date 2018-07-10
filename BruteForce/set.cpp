#include <iostream>
#include <string>
/*
11723 집합(수정 필요)
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
	/* 
	  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
	*/

	int n;
	cin >> n;
	res = 0; // 0 0 0 0 0 0 0 0 0 0 0 0 0...

	while (n--) {
		string op;
		cin >> op;
		int num;
		
		if (op == "add") {
			scanf("%d", &num);
			add(num);
			//printf("%d\n", res);
		}
		else if (op == "check") {
			scanf("%d", &num);
			if (check(num)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
		}else if(op=="remove") {
			int num;
			scanf("%d", &num);
			remove(num);
			//printf("%d\n", res);
		}
		else if (op == "toggle") {
			scanf("%d", &num);
			if (check(num)) {
				remove(num);
			}
			else {
				add(num);
			}
		}
		else if (op == "all") {
			res = (1<<21)-1;
			//printf("%d\n", res);
		}
		else if (op == "empty") {
			res = 0;
		}
	}
	
	return 0;
}
