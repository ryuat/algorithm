/* dfs bfs
 1260 간선 리스트 활용
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
    int from, to;
};

bool cmp(const Edge &e1, const Edge &e2){
    if(e1.from == e2.from){
        return e1.to < e2.to;
    }else
        return e1.from < e2.from;
};

Edge e[20001];
int cnt[1001];
bool check[1001];


void dfs(int node){
    check[node] = true;
    printf("%d ", node);
    for(int i=cnt[node-1];i<cnt[node];i++){
        int next = e[i].to;
        if(check[next] == false)
            dfs(next);
    }
};

void bfs(int start){
    queue<int> q;
    q.push(start); check[start] = true;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        printf("%d " , node);
        for(int i=cnt[node-1];i<cnt[node];i++){
            int next = e[i].to;
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
        scanf("%d %d", &e[i].from, &e[i].to);
        e[i+m].from = e[i].to;
        e[i+m].to = e[i].from;
    }
    
    m *= 2;
    sort(e, e+m, cmp);
    
    for(int i=0;i<m;i++){
        cnt[e[i].from] += 1; // 시작점의 갯수 세기
    }
    
    for(int i=1;i<=n;i++){
        cnt[i] += cnt[i-1]; // 누적합
    }
    
    dfs(v);
    printf("\n");
    memset(check, false, sizeof(check));
    bfs(v);
    puts("\n");
    
    return 0;
}
