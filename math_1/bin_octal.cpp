/*
 Baekjoon 1373 2진수 -> 8진수 변환
 3자리씩 묶기
 */
#include <iostream>
#include <string>

using namespace std;

int main(void){

    string s;
    string f_ans = ""; // 최종 결과
    int ans = 0; // 각 자리의 결과
    
    cin >> s;
    s = " " + s;
    int n = (int)s.size() - 1;
    
    for(int i=1;i<=n;i++){
        ans = ans * 2 + (s[i] - '0'); // -'0': 문자->숫자
    
        if((n-i)%3==0){ // 뒤(우측)에서 세자리씩 묶었을 때, 묶음 내 첫번째 인덱스
            f_ans += ans + '0'; // +'0': 숫자->문자
            ans = 0;
        }
    }
    cout << f_ans << endl;
    
    return 0;
}
