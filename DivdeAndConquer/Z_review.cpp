#include <iostream>
/*
 1074
 Z 리뷰
 */
using namespace std;

int pow2(int x){
    return 1<<x;
}

int solve(int x, int y, int n){ // 위치: x,y, 크기: 2^n
    if(n==1){ // 2x2일 경우
        return x*2+y;
    }
    if(x < pow2(n-1)){ //
        if(y < pow2(n-1)){ // x,y가 1사분면일 경우
            return solve(x, y, n-1);
        }else{ // x,y가 2사분면일 경우
            return solve(x, y-pow2(n-1), n-1) + pow2(2*n-2);
            // y좌표를 1사분면의 좌표처럼 맞춰주기 위해, y에서 pow2(n-1)을 빼준 좌표로 재귀호출하고
            // 1사분면의 개수 pow2(n-1) x pow2(n-1) = pow2(2*n-2)만큼 더해준다.
        }
    }else{
        if(y < pow2(n-1)){// x,y가 3사분면일 경우
            return solve(x-pow2(n-1), y, n-1) + pow2(2*n-2)*2;
            // 1사분면, 2사분면의 칸 수(pow2(2*n-2)*2를 더해준다.
        }else{ // x,y가 4사분면일 경우
            return solve(x-pow2(n-1), y-pow2(n-1), n-1) + pow2(2*n-2)*3;
        }
    }
}
int main(){
    int n, r, c;
    cin >> n >> r >> c;
    
    cout << solve(r, c, n);
    return 0;
}
