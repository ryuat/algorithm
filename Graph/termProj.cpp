#include <iostream>
#include <vector>

using namespace std;

vector<int> a(100001);
int check[100001];
int color[100001];
int cnt = 0; // 사이클아닌 노드의 수


void dfs(int node, int idx, int c){
    check[node] = idx; // 노드 방문
    color[node] = c; // 색(시점) 표시
    //printf("check[%d] = %d\n",node, idx);
    int next = a[node];
    if(check[next] == 0){ // 한 번도 방문한 적 없다면
        dfs(next, idx+1, c); // next노드 방문, idx+1번째로 방문, c 시점(호출 시점)
    }else if(check[next] > 0 && color[next] == c){
        // 방문한 적 있는데, 같은 시점이라면 사이클, next 이전 인덱스 = dfs실행 중에 탐색한 노드 중 사이클이 아닌 노드의 수
        cnt += check[next]-1;
        //printf("check[%d]-1 = %d\n", next,check[next]-1);
    }else if(check[next] > 0 && color[next] != c){
        // 방문한 적 있지만, 다른 시점이라면 해당 노드는 사이클이 될 수 없음
        cnt += check[node];
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        cnt = 0;
        int n;
        scanf("%d", &n);
        
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            check[i] = 0; // XX 필수 코드 (이유?)
            color[i] = 0; //
        }
        
        int col = 1;
        for(int i=1;i<=n;i++){
            int idx = 1;
            if(check[i] == false){
                dfs(i, idx, col++); // 노드, 방문idx, color
            }
        }
        
        printf("%d\n", cnt);
        /*
         for(int i=1;i<=n;i++){
         printf("%d노드) color: %d, check: %d\n", i, color[i], check[i]);
         }*/
    }
    return 0;
}
