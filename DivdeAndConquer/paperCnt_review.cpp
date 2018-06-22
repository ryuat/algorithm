/*
 1780
 종이의 개수 review
 */
#include <iostream>

using namespace std;

int a[2187][2187];
int ans[3] = {0, 0, 0};

bool check(int x, int y, int cnt){
    for(int i=x; i<x+cnt; i++){
        for(int j=y; j<y+cnt; j++){
            if(a[x][y] != a[i][j]){
                return false;
            }
        }
    }
    return true;
}

void divd(int x, int y, int cnt){
    if(check(x, y, cnt)){
        ans[a[x][y]+1] += 1; // -1:0, 0:1, 1:2
    } else{
        int n_cnt = cnt/3;
        for(int i=0;i<3;i++){ // 가로 3칸
            for(int j=0;j<3;j++){ // 세로 3칸
                divd(x+i*n_cnt, y+j*n_cnt, n_cnt);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }

    divd(0, 0, n);
    for(int i=0;i<3;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
