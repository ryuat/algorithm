#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> num(N); // num[N]: N번째 수
    vector<int> dp(N); // dp[N]: N번째 수를 끝으로 하면서, 문제의 모든 조건을 만족하는 최대 값
    
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    
    for(int i=0;i<N;i++){
        dp[i] = num[i];
        for(int j=0; j<i; j++){
            if(num[i] > num[j] && dp[i] < dp[j]+num[i])
                dp[i] = dp[j] + num[i];
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}
