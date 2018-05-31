/*
 6588 골드바흐의 추측
 */

#include <iostream>
#include <vector>

using namespace std;

int N = 1000000; // 최대값
bool s[1000001]; // 소수 여부(false:소수)
// int prime[10000001];

int main(void){
    // 에라토스테네스체 구현
    for(int i=2;i*i<=N;i++){
        if(s[i] == false){
            for(int j=i*2;j<=N;j+=i){
                s[j] = true;
            }
        }
    }
    
    // 골드바흐 추측 검증
    int n;
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        
        for(int i=2;i<=n-2;i++){
            if(s[i] == false && s[n-i] == false){ // i가 소수이고 n-i 연산. 결과가 소수이면
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
    
    return 0;
}
/*
cout cin 사용 시 시간초과
입력 N
N = a + b (a,b 소수)를 검증

N - a = b
N - a = 소수?
a(3..N-2)
*/
