/*
 다리 만들기 2번째 방법
 */
#include <iostream>
#include <utility>
#include <queue>

int a[100][100]; // (1:육지 2:바다)
int g[100][100]; // 그룹
int d[100][100]; // 거리
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            g[i][j] = 0; // 그룹 초기화
            d[i][j] = -1; // 거리 초기화
        }
    }
    // 육지의 그룹 번호 저장
    int grp = 0; //그룹번호
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 1 && g[i][j] == 0){ // 육지이고 탐색하지 않았다면
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                g[i][j] = ++grp; // 다음 그룹
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    //printf("%dx%d node 호출\n", x,y);
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(0<=nx && nx < n && 0 <= ny && ny < n){ // 인덱스 존재
                            if(a[nx][ny] == 1 && g[nx][ny]==0){ // 육지이면서 방문 안했다면
                                q.push(make_pair(nx,ny));
                                g[nx][ny] = grp; // 현재 grp
                            }
                        }
                    }
                    
                }
            }
        }
    }
    // dist 계산 + 그룹 채우기
    // start node
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 1 && d[i][j] == -1){ // 육지 노드 & 방문 x 를 모두 start로,
                q.push(make_pair(i,j)); // start 노드들 = 육지
                d[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(0<=nx && nx < n && 0 <= ny && ny < n){
                if(d[nx][ny] == -1){ // 방문 x
                    d[nx][ny] = d[x][y]+1;
                    g[nx][ny] = g[x][y];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int ans = n*20*n; // 임의의 큰 수
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){ // 인접노드
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(0<=nx && nx < n && 0 <= ny && ny < n){
                    if(g[nx][ny] != g[i][j]){ //인접노드의 그룹이 다를 경우
                        if(ans > d[i][j] + d[nx][ny]){ // 인접노드 거리의 합을 구하고
                            //printf("%dx%d - %dx%d\n",i,j ,nx,ny);
                            ans = d[i][j] + d[nx][ny]; // 최소값 저장
                        }
                    }
                }
            }
        }
    }
    /*
     printf("그룹\n");
     for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
     printf("%2d", g[i][j]);
     }
     printf("\n");
     }
     
     printf("거리\n");
     for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
     printf("%2d", d[i][j]);
     }
     printf("\n");
     }*/
    printf("%d\n", ans);
    return 0;
}

/*
 1. 그룹 저장
 2. dist 계산 + 바다 그룹 채우기
 3. 서로 다른 그룹이 인접한 바다 중 최소 dist
 */
