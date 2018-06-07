/* 그래프 인접리스트 bfs */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> a[11];
bool check[11];
queue<int> q;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1;i<=m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    
    check[1] = true; q.push(1); // 시작점
    while(!q.empty()){
        int x = q.front(); q.pop();
        printf("%d ", x);
        for(int i=1;i<=a[x].size();i++){
            int y = a[x][i];
            if(check[y] == false){
                check[y] = true;
                q.push(y);
            }
        }
    }
    
    return 0;
}
