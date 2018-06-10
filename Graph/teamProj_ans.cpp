/*
 9466 teamproejct
 */
#include <cstdio>

using namespace std;

int a[100001];
int check[100001];
int time[100001];

int dfs(int node, int cnt, int t){
    if (check[node] != 0){ // 재방문
        if(t != time[node]){ // 다른 dfs{
            return 0; // 재방문이면서 다른 시점이면 종료
        }
        return cnt-check[node];// 재방문이면서 같은 시점이면 사이클, 사이클 노드의 수
    }
    
    check[node] = cnt;
    time[node] = t;
    return dfs(a[node], cnt+1, t);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            check[i] = 0;
            time[i] = 0;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(check[i] == 0){
                ans += dfs(i, 1, i);
            }
        }
        printf("%d\n", n-ans);
        
    }
    return 0;
}


