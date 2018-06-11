/*
7576 토마토
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int day[1000][1000];
int status[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int m_row, m_col;
    scanf("%d %d", &m_col, &m_row);
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++)
            scanf("%d", &status[i][j]);
    }
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            day[i][j] = -1; // -1인 칸은 날짜를 -1로 설정
            if(status[i][j] == 1){ // 첫 날부터 익은 토마토들로 스타트
                q.push(make_pair(i,j));
                day[i][j] = 0; // 당일
            }
        }
    }
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        for(int k=0;k<4;k++){
            int n_row = row+dx[k];
            int n_col = col+dy[k];
            if(0<=n_row && n_row< m_row && 0<= n_col && n_col < m_col) // 인덱스 존재
                if(status[n_row][n_col] == 0){ // 익혀야할 토마토이면
                    q.push(make_pair(n_row, n_col));
                    day[n_row][n_col] = day[row][col]+1; // 하루 지나서
                    status[n_row][n_col] = 1; // 익음
                }
        }
    }
    
    int ans = -1;
    bool res = true;
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            if(status[i][j] == 0) // 익지 않은 것이 있다면
                res = false;  // 결과는 false bfs로 탐색 완료 불가능
            if(ans<day[i][j]) // 최대 day
                ans = day[i][j];
        }
    }
    
    printf("%d\n", res? ans:-1); // 탐색 가능하면 max ans, 불가하다면 -1
    
    return 0;
}

/*
 첫 날부터 익은 사과들(stats=1)이 시작노드가 되고
 이들을 큐에 먼저 넣고 시작하면
 여러 시작노드들이 동시에 탐색하는 듯이 작동한다.
 엄밀히 동시는 아니지만..
 */
