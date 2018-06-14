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
    
    // 노드1로부터 최대 거리의 정점 확인, bfs 탐색
    memset(dist, -1, sizeof(dist)); // 방문x -1 초기화
    queue<int> q;
    q.push(1); dist[1] = 0; // start 노드
    
    int max_node = 1, max_dist = 0;
    while(!q.empty()){
        int node = q.front(); // 현재 node
        q.pop();
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i].first;
            if(dist[next] == -1){ // 방문 x
                q.push(next);
                dist[next] = dist[node] + a[node][i].second; // 현재 노드까지의 거리
                if(max_dist < dist[next]){ // 최장거리 노드 저장
                    max_node = next;
                    max_dist = dist[next];
                }
            }
        }
    }
    /*
    printf("저장상태\n");
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            printf("base:%d, 도착:%d 가중:%d\n", i, a[i][j].first, a[i][j].second);
        }
        printf("\n");
    }
    
    printf("거리\n");
    for(int i=1;i<=n;i++){
        printf("node1->node%d까지의 거리:%d\n", i, dist[i]);
    }
    printf("최장거리 노드:%d 거리:%d\n", max_node, dist[max_node]);
    */
    // 최장거리 노드를 기준으로 다시 거리 계산
    
    memset(dist,-1,sizeof(dist)); // dist 초기화
    q.push(max_node); dist[max_node] = 0; max_dist = 0; // start 노드 // xx2 실수했던 부분: max_dist를 0으로 초기화하지 않아, maxnode로부터의 bfs(2번째 bfs)탐색에서의 max dist가 node1로부터의 bfs(1번째 bfs) 탐색에서의 max dist와 같은 경우 최장거리의 노드번호가 갱신되지 않음
    
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
                    max_dist = dist[next]; // xx1 실수했던 부분: 배열의 최대값을 구할 때, loop에서 인덱스와 값을 모두 갱신해주지 않음.
                }
            }
        }
    }
    /*
    printf("저장상태\n");
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            printf("base:%d, 도착:%d 가중:%d\n", i, a[i][j].first, a[i][j].second);
        }
        printf("\n");
    }
    
    printf("거리\n");
    for(int i=1;i<=n;i++){
        printf("node->node%d까지의 거리:%d\n", i, dist[i]);
    } */
    //printf("최장거리 노드:%d 거리:%d\n", max_node, dist[max_node]);
    
    printf("%d\n", dist[max_node]);
    return 0;
}

/*
 트리의 지름
 특정 노드를 루트로 하여 최장거리의 노드를 찾고
 최장거리의 노드를 루트로했을 때의 특정 정점과의 최장거리가 트리의 지름이 된다.
 => bfs를 두 번 탐색해야 한다.
 */
