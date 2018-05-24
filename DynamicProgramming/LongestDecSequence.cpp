#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> num(N);
    vector<int> dp(N);

    for(int i=0; i<N; i++){
        cin >> num[i];
    }
    for(int i=0; i<N; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(num[i] < num[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
