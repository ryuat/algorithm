/*
 baekjoon 2579
 계단 오르기
 1차원 배열
 */

#include <iostream>
#include <algorithm>
#include <vector>
#define max(a, b) ((a>b) ? a:b)

using namespace std;

int d[301];
int main(void){
    int n;
    cin >> n;
    
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    
    d[0] = num[0];
    d[1] = num[0]+num[1];
    //d[2] = max(num[1]+num[2], num[0]+num[2]); // 틀렸던 부분
    
    for(int i=2;i<n;i++){
        d[i] = max(d[i-3]+num[i-1]+num[i], d[i-2]+num[i]); // i번째가 연속 두 번일 경우 or 한 번일 경우
    }
    
    cout << d[n-1] << endl; // 틀렸던 부분
    return 0;
}

