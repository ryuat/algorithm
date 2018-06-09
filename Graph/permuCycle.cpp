/*
 10451: 순열 사이클
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a(1001);
bool check[1001];

void dfs(int node){
    check[node] = true;
    int next = a[node];
    if(check[next] == false)
        dfs(a[node]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        
        a.clear();
        memset(check, false, sizeof(check));
        
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(check[i] == false){
                dfs(i);
                ans++;
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
