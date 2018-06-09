/*
 이분그래프 1707
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int color[20001]; // 0: 방문x, 1:빨강, 2:파랑
vector<int> a[20001];

void dfs(int node, int c){
    color[node] = c;
    for(int i=0;i<a[node].size();i++){
        int next = a[node][i];
        if(color[next]==0)
            dfs(next, 3-c);
    }
}
int main(void){
    int N;
    scanf("%d", &N);
    while(N--){
        int n, m;
        scanf("%d %d", &n, &m);
        
        for (int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }
        
        while(m--){
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v); a[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            sort(a[i].begin(), a[i].end());
        }
        
        for(int i=1;i<=n;i++){
            if(color[i] == 0){
                    dfs(i, 1); // 그래프 탐색, 연결요소 고려, 시작노드는 빨간색
            }
        }
        
        bool ans = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                if(color[i] == color[a[i][j]]){
                    ans = false;
                }
            }
        }
        printf("%s\n", ans? "YES":"NO");
    }
    
    return 0;
}

