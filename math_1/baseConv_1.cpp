/*
 baekjoon 11005 진법변환1
 n/b ... r
 -> reverse r
 */

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string ans = "";
    int n, b, r;
    
    cin >> n >> b;
    
    while(n>0){
        r = n%b;
        if(r<10)
            ans += r + '0'; // r을 문자형 숫자로 변형 후 ans문자열에 붙임
        else
            ans += r - 10 + 'A'; // 10부터 문자 'A'로 치환하여 ans문자열에 붙임
        n = n/b;
    }
    
    reverse(ans.begin(), ans.end()); // loop에서 저장된 나머지 배열을 반대로 재저장
    
    cout << ans << endl;
    return 0;
}
