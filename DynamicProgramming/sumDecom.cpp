/*
 baekjoon 2225 합분해
 d[k][n]: n합 k개 분해 경우의 수
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000000

using namespace std;

long long d[201][201]; // d[k][n]: n합 k개 분해 경우의 수

int main(void){
    
    int n, k;

    cin >> n;
    cin >> k;
    
    for(int i=0;i<=n;i++)
        d[1][i] = 1;
    
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int c=0; c<=j;c++){
                d[i][j] += d[i-1][j-c]%mod;
            }
        }
    }
   
    cout << d[k][n]%mod<<endl;
    
    return 0;
}

