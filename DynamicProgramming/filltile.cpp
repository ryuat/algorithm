/*
   타일 채우기 baekjoon 2133
   d[n-j*2] 열이 짝수개씩 늘어날 수록, 경우의 수가 2가지씩 추가.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> d(n+1);

    d[0] = 1;
   
    
    for(int i=2;i<=n;i++){
        d[i] = 3*d[i-2];
        for(int j=2;j<=i/2;j++){
            d[i] += 2*d[i-j*2];
        }
    }
    cout << d[n] << endl;
    return 0;
}
