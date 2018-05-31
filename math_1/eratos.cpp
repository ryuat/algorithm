/*
 1929 에라토스테네스 체
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    
    int m, n;
    cin >> m >> n;
    
    vector<bool> s(n+1);
    
    s[0] = s[1] = true;
    for(int i=2;i*i<=n;i++){
        if(s[i] == false){
            for(int j=i*2;j<=n;j+=i){
                s[j] = true;
            }
        }
    }
    for(int i=m;i<=n;i++){
        if(s[i] == false)
            cout << i << "\n";
    }
    return 0;
}
/*
1. 2부터 N까지 숫자를 저장.
2. 가장 작은 수가 소수인지 확인
3. 소수라면 배수를 모두 제거

+ 제곱수부터 제거하면 된다.
+ sqrt(N)까지만 돌리면 된다.
+ j의 오버플로우를 고려해야 한다.
*/

