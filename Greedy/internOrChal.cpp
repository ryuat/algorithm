/*
 2875
 대회 or 인턴
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int min(int val1, int val2){
    return (val1 < val2) ? val1:val2;
}
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int team = min(n/2, m); // 남자/2와 여자 수 중 작은 값 만큼 팀을 만들 수 있다.
    int r = (n-team*2) + (m-team); // 팀 구성 후 남는 사람의 수 (남, 여)
    
    while(k--){ // 인턴참여할 k명을 찾는다
        if(r == 0){ // 남는 사람이 없을 경우
            team--; // 한팀을 해체
            r = 2; // 해체한 한 팀에서 한명을 제외한 2명이 팀 구성후 남는 사람의 수가 된다.
        }else{
            r--; // 남는 사람이 있을 경우 남는 사람이 인턴에 참여
        }
    }
    
    printf("%d\n", team);
    return 0;
}

/*
팀 수
팀 제외 나머지 사람 수

인턴은 나머지 사람이 있을 경우 그 사람으로
나머지 사람이 없을 경우 팀 해체
*/
