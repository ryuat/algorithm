#include <iostream>

int main(void){
    long long A, B, C, D;
    
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    for(long long i=B; i!=0; i/=10){ // B의 자리수 만큼 순회
        A *= 10;
    }
    for(long long i=D; i!=0; i/=10){
        C *= 10;
    }
    
    printf("%lld", A+B+C+D);

    return 0;
}

