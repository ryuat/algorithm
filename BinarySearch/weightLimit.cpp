#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

/* 
1939
�߷����� 
*/ 
using namespace std;

int start_isl, end_isl;
vector<pair<int, int>> a[100001];
bool check[10001];

int dfs(int node, int x) {

	if (check[node]) { // dfsŽ�� �� ��湮�� ��� ����Ŭ ���� => ���� ���
		return false;
	}
	
	check[node] = true;

	if (end_isl == node) {
		return true;
	}
	
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i].first;
		int limit = a[node][i].second;
		//printf("�������:%d  �Ѱ�:%d\n", next, limit);
		if (limit >= x) { // ���԰� ���
			if (dfs(next, x)) {// ���� ��嵵 ����ϴٸ�
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	while (m--) {

		int start, end, limit;
		scanf("%d %d %d", &start, &end, &limit);
		a[start].push_back(make_pair(end, limit));
		a[end].push_back(make_pair(start, limit));
	}

	scanf("%d %d", &start_isl, &end_isl);
	
	int min_w = 1;
	int max_w = 1000000000;
	int ans = 0;
	
	while (min_w <= max_w) {
		memset(check, false, sizeof(check));
		int mid = (min_w + max_w) / 2;
		if (dfs(start_isl, mid)) {
			if (mid > ans) {
				ans = mid;
			}
			min_w = mid + 1;
		}
		else {
			max_w = mid - 1;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}