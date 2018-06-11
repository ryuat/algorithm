/*
 2667
 단지번호붙이기 (1) 그룹번호 출력
 */
#include <iostream>

using namespace std;

int a[25][25];
int group[25][25];
bool check[25][25];

void dfs(int row, int col, int grp, int max_idx){
    if (0 <= row && row < max_idx && 0 <= col && col < max_idx ){ // 방(인덱스)이 존재하는데
        if(check[row][col] == false && a[row][col]==1){ // 현재 노드를 탐색하지 않았다면
           // printf("%d그룹: (%d,%d)\n", grp, row, col);
            check[row][col] = true; // 탐색 표시
            group[row][col] = grp; // 그룹 번호 저장
            dfs(row, col+1, grp, max_idx); // 우
            dfs(row+1, col, grp, max_idx); // 하
            dfs(row, col-1, grp, max_idx); // 좌
            dfs(row-1, col, grp, max_idx); // 상
        }
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    int grp = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j] == false && a[i][j]==1)
                dfs(i, j, grp++, n);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d",group[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
        
