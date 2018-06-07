/*
 1260 DFS와 BFS
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

bool check[1001];
vector<int> a[1001];

void dfs(int node){
    check[node] = true;
    printf("%d ", node);
    for(int i=0;i<a[node].size();i++){
        int next = a[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}
void bfs(int start){
    memset(check, false, sizeof(check)); // check 배열 요소들 모두 false로 변경
    queue<int> q;
    q.push(start); check[start] = true;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        printf("%d ", node);
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
        
    }
}

int main(void){
    int n, m, v; // n:정점, m:간선, v:시작
    scanf("%d %d %d", &n, &m, &v);
    
    for(int i=1;i<=m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(v);
    puts("");
    bfs(v);
    puts("");
    return 0;
}
