/*
 연결요소 11724
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool check[1001]; // 방문 횟수
vector<int> a[1001];

void dfs(int node){
    check[node] = true;
    //printf("%d 방문 ", node);
    for(int i=0;i<a[node].size();i++){
        int next = a[node][i];
        if(check[next]==false)
            dfs(next);
    }
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    while(m--){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        sort(a[i].begin(), a[i].end());
    }
    
    int cnt = 1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(check[i] == false){
            dfs(i);
            ans++;
        }
        if(cnt==0){
            printf("%d 개", i);
            break;
        }
        for(int i=1;i<=n;i++){
            cnt += check[i];
        }
    }
    printf("%d\n", ans);
    
    return 0;
}

