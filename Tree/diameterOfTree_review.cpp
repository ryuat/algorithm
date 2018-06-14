/*
 1167 트리의 지름
 */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int,int>> a[100001]; // pair<노드,거리>
int dist[100001];

int bfs(int start){
    memset(dist, -1, sizeof(dist)); // 방문x -1 초기화
    queue<int> q;
    q.push(start); dist[start] = 0;
    int max_node = start, max_dist = dist[start];
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i].first;
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[node] + a[node][i].second;
                if(max_dist < dist[next]){
                    max_node = next;
                    max_dist = dist[next];
                }
            }
        }
    }
    return max_node;
}

int main(){
    int n;
    scanf("%d" , &n);
    
    for(int i=0;i<n;i++){ // n회
        int base, ob, w;
        scanf("%d", &base);
        if(base == -1) continue;
        
        while(1){
            scanf("%d", &ob);
            if(ob == -1) break;
            scanf("%d", &w);
            a[base].push_back(make_pair(ob,w));
            }
    }
    int start = bfs(1);
    printf("%d", dist[bfs(start)]);
    return 0;
}
