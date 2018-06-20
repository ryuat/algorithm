/*
 1080 행렬
 */
#include <iostream>
using namespace std;

int a[50][50];
int ans[50][50];
int dx[] = {0, 0, 1, 1, 1, 2, 2, 2};
int dy[] = {1, 2, 0, 1, 2, 0, 1, 2};
int n, m;
void flip(int x, int y){
    a[x][y] = 1-a[x][y];
    
    for(int k=0;k<8;k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(0 <= nx && nx <= n && 0 <= ny && ny <= m){
            a[nx][ny] = 1-a[nx][ny];
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &ans[i][j]);
        }
    }
    
    int cnt = 0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(a[i][j] != ans[i][j]){
                flip(i,j);
                cnt++;
            }
        }
    }
    
    bool res = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] != ans[i][j]){
                res = false;
            }
        }
    }
    
    printf("%d\n", (res? cnt:-1));
    
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%1d", a[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%1d", ans[i][j]);
        }
        printf("\n");
    }*/
    
    return 0;
}
