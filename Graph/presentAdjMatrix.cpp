/* 양방향 그래프 인접행렬로 표현하기 */

#include <cstdio>
#include <vector>

int a[10][10];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<m;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = a[v][u] = w;
    }
    return 0;
}
