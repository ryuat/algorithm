/*
 이분그래프 1707
 잘못된 방법
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int check[20001]; // 방문 횟수
vector<int> a[20001];
int c = 2;
int s = 1;

void dfs(int node){
    s *= -1;
    c += s;
    //printf("check[%d] = %d\n", node, c);
    check[node] = c;
    //printf("%d ", node);
    for(int i=0;i<a[node].size();i++){
        int next = a[node][i];
        if(check[next]==false)
            dfs(next);
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
            check[i] = 0;
        }
        
        while(m--){
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v); a[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            sort(a[i].begin(), a[i].end());
        }
        dfs(1); // 그래프를 1부터 탐색, 노드1은 빨간색
        
        bool ans = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                if(check[i] == check[a[i][j]]){
                    ans = false;
                }
            }
        }
        printf("%s\n", ans? "YES":"NO");
    }
    
    return 0;
}

/*
 이분그래프 1707
 잘못된 방법
 
 호출함수 - 피호출함수 간에 연결고리 (color: 호출함수에서의 node가 빨강 => 피호출함수에서 node는 파랑)
 를 구현할 때, 전역변수로 구현할 수 없다.
 
 4번 노드에서 next 호출이 없으므로, 3번으로 되돌아간다.
 3번으로 돌아와서 5번을 호출하므로, 3번과 5번은 빨/파로 설정이 돼야 한다.
 그러나, 전역변수로 switch를 구현할 경우, 결국 4번과 5번 간의 연결고리로 구현한 것이 된다.
 
 반례)
 1
 5 6
 1 2
 2 3
 3 4
 4 1
 1 5
 5 3
 */
