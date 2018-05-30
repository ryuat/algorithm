/* base conversion 11576
 a진법 -> 10진법 -> b진법
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a, b, n; // a -> b진법, n개
    int ans=0;
    cin >> a >> b >> n;

    // a진수 => 10진수
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        ans = ans*a + num;
    }
    // 10진수 => b진수
    vector<int> ans_b(25); // 25자리
    int idx=0;
    while(ans){
        int r;
        r = ans%b; // 나머지
        ans_b[idx] = r;
        ans = ans/b;
        idx++;
    }
    for(int i=idx-1;i>=0;i--) // idx-1부터
        cout <<ans_b[i] << " ";
    
    return 0;
}

