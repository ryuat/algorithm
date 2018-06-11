#include <iostream>
#include <cstring>

using namespace std;
int v[100001];
int check[100001];
int lt[100001];

int dfs(int a, int cnt, int t){
    if(check[a] > 0){
        if(lt[a] == t){
            return cnt - check[a]; // 같은 시점 노드 재방문 => 사이클 생성, 총 길이 중 현재 노드의 cnt만큼 빼면 dfs 진행 중 생성된 사이클에 포함된 노드 수
        }
        return 0; // 다른 시점 노드를 방문, 탐색한 노드 중 사이클 노드 수는 0
    }
    
    //그렇지 않다면, 방문한 적 없는 노드
    check[a] = cnt; // 해당 탐색에서 몇 번째 방문인지 저장
    lt[a] = t;// 해당 탐색이 어느 시점인지 저장
    return dfs(v[a], cnt+1, t);
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        memset(check, 0, sizeof(check));
        memset(lt, 0, sizeof(lt));
        memset(lt, 0, sizeof(lt));
        
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &v[i]);
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(check[i] == false){
                ans += dfs(i, 1, i);
            }
        }
        printf("%d\n", n-ans);
    }
    
    return  0;
}

