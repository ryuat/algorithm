#include <iostream>

/*
 2447 별찍기
 */
using namespace std;

char a[7000][7000];

void p(int x, int y, int cnt){
    for(int i=x;i<x+cnt;i++){
        for(int j=y;j<y+cnt;j++){
            a[i][j] = ' ';
        }
    }
}
void solve(int x, int y, int cnt){
    if(cnt == 1){  // 크기가 1까지 분할되었을 때 별을 찍는다.
        a[x][y] = '*';
    }else{          // 크기가 1이 아닐 경우
        for(int i=0;i<3;i++){ // 가로 3칸
            for(int j=0;j<3;j++){ // 세로 3칸으로 나눈다.
                if(i==1 && j == 1){
                    p(x+cnt/3*i, y+cnt/3*j, cnt/3); // 가운데 칸은 공백을 찍는다.
                }else{
                    solve(x+cnt/3*i, y+cnt/3*j, cnt/3); // 그 외의 칸은 9개의 크기로 분할한다.
                }
            }
        }
    }
}
       
int main(){
    int n;
    scanf("%d", &n);
    
    solve(0, 0, n); // 0x0부터 n개

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
