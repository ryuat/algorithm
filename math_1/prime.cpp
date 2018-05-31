/*
 baekjoon 1978 소수 찾기
 O(sqrt(N))
 xy = N 그래프는
 y=x 대칭
 
 두 그래프의 교점은
 y = x = sqrt(N)
 */
#include <iostream>
#include <cmath>

using namespace std;

bool prime(int num){
    if(num<=1)
        return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int main(){
    int n, num, cnt=0;
    cin >> n;
    
    while (n--){
        cin >> num;
        if(prime(num)) cnt++;
    }
    
    cout << cnt;
    return 0;
}
