/* 그래프 인접행렬 - DFS */

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int a[10][10]; // 노드 10개 가정
bool check[10];

void dfs(int x){ // x를 방문해라
    check[x] =true;
    printf("%d ", x);
    for(int i=0;i<10;i++){
        if(a[x][i] == 1 && check[i] == false)
            dfs(x);
    }
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<n;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    return 0;
}
