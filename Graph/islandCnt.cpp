/*
 4963 섬의 개수
 */
#include <iostream>
#include <cstring>

using namespace std;
int a[50][50];
bool check[50][50];
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
int max_row, max_col;

void dfs(int row, int col){
    check[row][col] = true;
    for(int k=0;k<8;k++){
        int n_row = row + dx[k]; int n_col = col + dy[k];
        if(a[n_row][n_col] == 1 && check[n_row][n_col] == false)
            if(0 <= n_row && n_row < max_row && 0 <= n_col && n_col < max_col ){
                dfs(n_row, n_col);
        }
    }
}
int main(){
    while(true){
        for(int i=0;i<50;i++){
            memset(a[i],0,sizeof(a[i]));
            memset(check[i],false,sizeof(check[i]));
        }
        
        scanf("%d %d", &max_col, &max_row);
        if(max_col==0 && max_row == 0) break;
        
        for(int i=0;i<max_row;i++){
            for(int j=0;j<max_col;j++){
                scanf("%d", &a[i][j]);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<max_row;i++){
            for(int j=0;j<max_col;j++){
                if(a[i][j] == 1 && check[i][j] == false){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
