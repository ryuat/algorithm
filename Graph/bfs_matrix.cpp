/* 그래프 인접행렬 bfs */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a[11][11];
bool check[11];
queue<int> q;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1;i<=m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    
    check[1] = true; q.push(1); // 시작점
    while(!q.empty()){
        int x = q.front(); q.pop();
        printf("%d ", x);
        for(int i=1;i<=n;i++){
            if(a[x][i] == true && check[i] == false){
                check[i] = true;
                q.push(i);
            }
        }
    }
    
    return 0;
}
