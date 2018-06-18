/*
 2875
 대회 or 인턴 리뷰
 
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int team=0;
    
    while(n>=2 && m>=1 && n+m>=k+3){ // 팀 구성 + 인턴 가능한 인원수라면
        n -= 2; // 남자 두명
        m -= 1; // 여자 한명
        team++; // 한 팀
    }
    
    printf("%d\n", team);
    return 0;
}
