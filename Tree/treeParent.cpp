/*
 11725 트리의 부모 찾기
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100001];
int parent[100001];
int depth[100001];
bool check[100001];

int main(void){
    
    int n;
    scanf("%d", &n);
    for(int i=2;i<=n;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
        //  parent[i] = 0; // 초기화
    }
    
    queue<int> q;
    q.push(1);
    check[1] = true;
    depth[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i];
            if(check[next]==false){
                check[next]=true;
                parent[next] = node;
                depth[next] = depth[node] + 1;
                q.push(next);
            }
        }
    }
    for(int i=2;i<=n;i++){
        printf("%d\n", parent[i]);
    }
    return 0;
}


