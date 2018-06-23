#include <iostream>

/*
 1992 쿼트트리
 */

using namespace std;

int a[64][64];

bool check(int x, int y, int cnt){
    for(int i=x;i<cnt+x;i++){
        for(int j=y;j<cnt+y;j++){
            if(a[x][y] != a[i][j]){
                //cout << a[x][y] << " != " << a[i][j]<<endl;
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int cnt){
    if(check(x,y,cnt)){
        printf("%d", a[x][y]);
    }else{
        printf("(");
        int ncnt = cnt/2;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
               // printf("solve(%d %d %d)\n",x+i*ncnt, y+j*ncnt, ncnt);
                solve(x+i*ncnt, y+j*ncnt, ncnt);
            }
        }
        printf(")");
    }
    
}
int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &a[i][j]);
        }
    }

    solve(0, 0, n);
    return 0;
}
