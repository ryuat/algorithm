/*
 baekjoon 2089 -2진수 재귀 활용
 */
#include <iostream>
#include <string>

using namespace std;

void conv(int N){
    if(N==0) return;
    
    if(N%(-2) < 0){
        conv(N/(-2)+1);
        cout << N%(-2) *(-1);
    }else {
        conv(N/(-2));
        cout << N%(-2);
    }
}

int main(){
    int N;
    cin >> N;
    
    if(N==0) cout << 0;
    conv(N);
    return 0;
}
