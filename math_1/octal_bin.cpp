/*
 Baekjoon 1212 8진수 -> 2진수 변환
 3자리씩 묶기
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    
    string s;
    
    cin >> s;
    
    s = " " + s;
    int n = (int)s.size() - 1;
    int r;
    
    for(int i=1;i<=n;i++){
        string ans = "";
        int cnt = 0;
        int x = s[i] - '0'; // 숫자로 변환
        while(x){
            r = x%2;
            x = x/2;
            cnt++;
            ans += r + '0'; // 문자로 변환하여 문자열에 저장
        }
        reverse(ans.begin(), ans.end());
        if(cnt == 2) // 2번만 나눴다면 "0"을 붙인다. 예) "0" + "01"
            ans = "0" + ans;
        else if(cnt == 1) // 1번만 나눴다면 "00"을 붙인다. 예) "00" + "1"
            ans = "00" + ans;
        else if(cnt == 0) // 한 번도 나누지 못했다면 "000"을 붙인다.
            ans = "000" + ans;
        
        if(i==1 && ans[0] == '0' && ans[1] == '0') // 8진수의 첫자리이면서 이진수 첫 두자리가 00인 경우
            cout << ans[2];
        else if (i==1 && ans[0] == '0')// 8진수의 첫자리이면서 2진수 첫자리가 0인 경우
            cout << ans[1] << ans[2];
        else
            cout << ans;
    }
    cout << endl;
    return 0;
}

