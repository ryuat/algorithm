/*
2178 미로 탐색
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int a[100][100];
int dist[100][100];
bool check[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int max_row, max_col;

void bfs(int s_row, int s_col){
    queue<pair<int,int>> q;
    q.push(make_pair(s_row, s_col));
    check[s_row][s_col] = true;
    dist[s_row][s_col] = 1;
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
       
        for(int k=0;k<4;k++){
            int n_row = row+dx[k];
            int n_col = col+dy[k];

            if(0 <= n_row && n_row < max_row && 0 <= n_col && n_col < max_col){
                if(a[n_row][n_col] == 1 && check[n_row][n_col] == false){
                    q.push(make_pair(n_row,n_col));
                    check[n_row][n_col] = true;
                    dist[n_row][n_col] = dist[row][col] + 1;
                }
            }
        }
    }
}
int main(){
    scanf("%d %d", &max_row, &max_col);
    for(int i=0;i<max_row;i++){
        for(int j=0;j<max_col;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0, 0);
    printf("%d\n", dist[max_row-1][max_col-1]);
    
    return 0;
}

/*
 간선의 가중치가 1인 그래프를 bfs 방식으로 탐색하면
 최단거리 알고리즘과 동일
 */
