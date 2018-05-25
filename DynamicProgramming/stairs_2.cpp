/*
 baekjoon 2579
 계단 오르기
 2차원 배열
 d[n][s] = n번째 올랐을 때, s번 연속 계단을 밟은 상태
 */

#include <iostream>
#include <algorithm>
#include <vector>
#define max(a,b) (((a)>(b)) ? (a):(b))

using namespace std;

int d[301][3];
int main(void){
    int n;
    cin >> n;
    
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    
    d[0][1] = d[0][2] = num[0];
    
    for(int i=1; i<n ; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + num[i];
        d[i][2] = d[i-1][1] + num[i];
    }
    
    cout << max(d[n-1][1], d[n-1][2]) << endl;
    return 0;
}
