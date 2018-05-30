/*
 baekjoon 2089 -2진수
 2진수 원리와 동일하게
    n/2  .. r
    n/-2 .. r
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string ans="";
    int n, r;
    cin >> n;
    if(n==0){
        cout << "0" << endl;
        return 0;
    }
    while(n){ // n이 0이 되면 종료.
        r = n%(-2); // n을 -2로 나눈 나머지
        if(r<0){// 나머지가 음수(-1)라면
            n = n/(-2)+1; // 몫을 1 추가한다. 몫을 1추가함으로써 나머지는 -1에서 1로 바뀐다(아랫줄).
            r *= -1;
            ans += r + '0'; // 최종 결과값에 연결
            /* 몫을 1추가하는 이유: n%(-2) 연산 시 나머지가 음수로 나오는 경우를 처리.
               예) -1%-2 = -1,
                  실제 -2진수를 구할 때 한 묶음을 더해(몫++) -1%-2 = 1이 돼야한다.
                  즉, 실제 -2진수는 1과 0만 가지는 수이므로 나머지가 항상 양수이어야 한다. 나머지가 양수로 나오도록
             
                  r<0일 경우
                   피제수-(몫 * 제수)        =>     피제수-((몫+1)*제수) 형태로 변환
               예) -1   -(0 * (-2)) = -1  =>     -1  -((0+1)*(-2)) = 1
            */
        }else{
            n = n/(-2);
            ans += r + '0';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
