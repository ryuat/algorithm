/* dfs bfs
 1260 dfs(stack) - 인접리스트 활용
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int start){
    stack<int> s;
    s.push(start); check[start] = true;
    printf("%d ", start);
    
    while(!s.empty()){
        int node = s.top();
        check[node] = true;
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i];
            if(check[next]==false){ // 빈 노드를 찾으면, stack push 후 다음 노드로 이동
                s.push(next);
                printf("%d ", next);
                break;
            }
            if(i==a[node].size()-1){ // 위 if문에 한 번도 안걸리면
                s.pop();
            }
        }
    }
};

void bfs(int start){
    queue<int> q;
    q.push(start); check[start] = true;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        printf("%d " , node);
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i];
            if(check[next] == false){
                q.push(next);
                check[next] = true;
            }
        }
    }
}
int main(void){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    
    for(int i=0;i<m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++)
        sort(a[i].begin(), a[i].end());
    
    dfs(v);
    printf("\n");
    memset(check, false, sizeof(check));
    bfs(v);
    puts("\n");
    
    return 0;
}
