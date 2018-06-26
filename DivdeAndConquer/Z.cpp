#include <iostream>

/*
 1074
 Z
 */

using namespace std;

//int a[32768][32768];

int k=0;
int x2, y2; // 찾고자 하는 위치의 인덱스

int pow(int a, int x){
    int ans = 1;
    while(x--){
        ans = ans*a;
    }
    return ans;
}
void solve(int x, int y, int cnt){
    if(cnt == 2){ // 2칸짜리 까지 분할됐을 때
        for(int i=x;i<x+cnt;i++){ // 가로 2
            for(int j=y;j<y+cnt;j++){ // 세로 2 만큼
                if(i == x2 && j == y2){
                    printf("%d\n", k); // 방문한 칸이 x, y(찾으려는 위치)라면 출력
                }
                k++; // 방문한 칸 수
            }
        }
        return;
    }else{ // 가로 세로 각각 칸의 수가 2보다 클 경우
        for(int i=0;i<2;i++){ // 가로 2
            for(int j=0;j<2;j++){ // 세로 2
                solve(x+cnt/2*i, y+cnt/2*j, cnt/2); // 분할
            }
        }
    }
    
}
int main(){
    int n, r, c;
    cin >> n >> r >> c;
    x2 = r;
    y2 = c;
    int N = pow(2,n);
    solve(0, 0, N);
    /*
    cout << "pow:"<<N<<endl;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%3d", a[i][j]);
        }
        cout << endl;
    }
   printf("%d\n", k);
    */
    return 0;
}
