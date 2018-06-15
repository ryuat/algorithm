/*
 11047
 동전 0
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int ans = 0; // 지폐 or 동전의 개수
    for(int i=n-1;i>=0;i--){
        if(k==0) break;
        ans += k/a[i]; // k원을 제일 큰 지폐부터 거슬러 준다.
        k %= a[i]; // k원을 제일 큰 지폐로 거슬러준 후의 나머지
    }
    
    cout << ans<<'\n';
    
    return 0;
}
