/*
 2331 반복수열
 */
#include <iostream>

using namespace std;

int check[1000000];
int pow(int x, int p){
    int ans = 1;
    while(p--){
        ans = ans*x;
    }
    return ans;
}
int next(int a, int p){
    int ans = 0;
    while(a>0){
        ans += pow(a%10, p); // 끝 한자리 뽑아서 제곱하기
        a /= 10; // 마지막 자리 지우기
    }
    return ans;
}
int func(int a, int p, int idx){
    if(check[a] != 0) // a노드를 이미 방문했다면
        return check[a] - 1; // 그 수열 인덱스부터 사이클을 구성 => 그 앞까지가 반복되지 않는 구간
    
    check[a] = idx; // 첫 방문이라면, a노드가 수열에서 몇 번째인지 저장(수열 인덱스 저장)
    int next_a = next(a, p);
    return func(next_a, p, idx+1);
}

int main(void){
    int a, p;
    scanf("%d %d", &a, &p);
    
    printf("%d\n", func(a, p, 1));
    return 0;
}

/*
 방문했던 노드를 또 방문 => 해당 노드부터 사이클 생성
 */
