/*
 11729
 하노이 탑 이동 순서
 */
#include <iostream>

void solve(int n, int x, int y){ // n이하의 원판, x위치에서 y위치로 이동
    if(n==0) return;
    solve(n-1, x, 6-x-y); // n을 x에서 y로 이동시키려면 먼저, n-1이하의 원판을 z위치로 이동해야 한다
    printf("%d %d\n", x, y); // n을 x에서 y로 이동시킨다.
    solve(n-1, 6-x-y, y); // n-1이하의 원판들을 모두 y로 이동시킨다.
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n)-1);
    solve(n, 1, 3);
    
    return 0;
}
/*
 1<<n => 2^n
 하노이 이동 횟수의 일반항은
 d[n] = 2*d[n-1] + 1
 
 d[n]은 공비가 2인 등비계차수열
 d[n] = d[1] + sum(b[n-1])  : d[1]과 계차수열의 합
 
 등비수열 합 공식에 의해 sum(b[n-1]) = 2^n-2
 
 따라서 d[n] = 1+2^n-2 = 2^n-1
 */
