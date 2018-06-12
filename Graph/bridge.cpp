/* 2146 다리 만들기 */

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int a[100][100];
int group[100][100]; // 그룹번호, + 방문 체크 역할 (1이상:o, 0:x)
int dist[100][100]; // 한 섬의 각각의 육지에서 다른 섬의 육지까지의 거리 + 방문 체크 역할 (1:o, -1:x)
int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int s_row, int s_col, int grp){
    queue<pair<int,int>> q;
    group[s_row][s_col] = grp;
    q.push(make_pair(s_row, s_col)); // 시작 노드 push
    
    while(!q.empty()){
        int row = q.front().first; // 현재 노드
        int col = q.front().second; // 현재 노드
        q.pop(); // 현재 노드 pop
        
        for(int k=0;k<4;k++){
            int n_row = row+dx[k]; // 다음 노드
            int n_col = col+dy[k]; // 다음 노드
            if(0 <= n_row && n_row < N && 0 <= n_col && n_col < N) // 인덱스 존재
                if(a[n_row][n_col] == 1 && group[n_row][n_col] == 0){ // 다음노드가 육지이고 방문하지 않았다면
                    q.push(make_pair(n_row, n_col)); // 다음 노드 push
                    group[n_row][n_col] = grp; // 다음 노드는 현재 노드와 같은 그룹 번호를 저장
                }
        }
    }
}

int main(){
    scanf("%d", &N);
    int min_dist = N*2*100; // 큰 수 임의 저장
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    // 그룹번호 0으로 초기화
    for(int i=0;i<N;i++)
        memset(group[i], 0, sizeof(group[i]));
    
    // 그룹 분류
    int grp=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(group[i][j] == 0 && a[i][j] == 1) // 탐색 안했을 경우 & 육지일 경우
                bfs(i, j, grp++);
        }
    }
    /*
    printf("group 확인 코드 \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%2d", group[i][j]);
        }
        printf("\n");
    }*/
    
    /* 다리 탐색 목적의 bfs */
    grp = grp - 1; // 섬의 개수

    for(int g=1;g<=grp;g++){ // 각각의 육지그룹을 기준으로 모든 육지의 dist를 계산
        queue<pair<int,int>> q;
        // dist 초기화 (+방문 체크 역할 (0이상:o, -1:x))
        for(int i=0;i<N;i++)
            memset(dist[i], -1, sizeof(dist[i]));
        
        // start 노드 push
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(group[i][j] == g) {// 기준 그룹이라면 시작 노드로 push
                    q.push(make_pair(i,j));
                    dist[i][j] = 0; // 제 자리이므로 거리는 0
                }
            }
        }
        
        // 기준 그룹 이외 모든 육지의 dist 계산
        while(!q.empty()){
            // 현재 노드
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // 다음 노드 찾기
            for(int k=0;k<4;k++){
                int n_row = row+dx[k];
                int n_col = col+dy[k];
                if(0<=n_row && n_row<N && 0<=n_col && n_col<N) // 인덱스 조건
                    if(dist[n_row][n_col] == -1){ // 방문하지 않았다면
                        q.push(make_pair(n_row, n_col)); // 다음 노드 push
                        dist[n_row][n_col] = dist[row][col] + 1; // 그 다음 노드의 거리는 +1
                    }
            }
        }
        // 확인용 출력코드
        /*
        printf("dist 확인 코드, 기준 섬: %d\n", g);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%2d", dist[i][j]);
            }
            printf("\n");
        }
         */
        // min dist 찾기
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(group[i][j] != g && group[i][j] != 0){ // 자신의 group이 아닌, 육지의 dist
                    if(min_dist > dist[i][j]){ // 최소값 찾기
                        min_dist = dist[i][j];
                    }
                }
            }
        }
    }
    printf("%d\n", min_dist-1);
    return 0;
}
/*
 토마토 문제 + 단지번호 문제
 
 섬의 그룹(단지번호)을 저장하고
 각각의 그룹에서 모든 육지(ij)의 dist를 저장
 
 특정 그룹을 기준으로 자신의 섬그룹이 아닌 최소 dist를 찾는 작업을
 모든 그룹에 대해 반복한다.
 */
