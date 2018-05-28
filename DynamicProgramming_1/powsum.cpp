#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    int n, r;
    cin >> n;
    vector<int> d(n+1);

    d[0] = 0;
   
    for(int i=1;i<=n;i++){
        d[i] = i; // d[i]를 1^2의 조합으로 가정. => 경우의 수의 최대값, d[4] = d[1]+d[1]+d[1]+d[1] = 4
        for(int j=1; j<=sqrt(i);j++){ // i보다 작은 제곱수들을 첫 항으로
            r = i-pow(j,2); // j^2을 첫항으로 하여 이를 제외한 나머지
            if(d[i] > 1+d[r]) // j^2의 min값 찾기
                d[i] = 1+d[r];
        }
    }
    
    cout << d[n] << endl;
    return 0;
}
