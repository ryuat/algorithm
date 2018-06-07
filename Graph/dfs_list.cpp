/* 그래프 인접리스트 - DFS */

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<int> a[10];
bool check[10];

void dfs(int x){
    check[x] = true;
    printf("%d ", x);
    for(int i=0;i<a[x].size();i++){
        int y;
        y = a[x][i]; // a[x] 벡터에서 i번째
        if(check[y] == true)
            dfs(y);
    }
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    return 0;
}
