/*
 1541 잃어버린 괄호
 */
#include <iostream>
#include <cstring>

using namespace std;

char str[51];

int main(){
    
    scanf("%s", str);
    int num=0, ans=0, sign=1; // 숫자, 결과, 부호
    for(int i=0;i<=strlen(str);i++){ // 마지막 항 연산을 위해 loop를 한 바퀴 더 돌도록 strlen 포함
        if('0'<=str[i] && str[i]<='9'){ // 숫자이면 더한다.
            num = num*10 + (str[i]-'0');
        } else{ // 숫자가 아니면 부호 확인
            ans += num*sign;
            num = 0; // 다음 숫자를 구성하기 위해 초기화
            if(sign==1 && str[i] == '-'){
                sign = -1; // 부호가 -이면 빼기 연산 수행
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
/*
 -부호가 처음 나온 시점부터 뒷부분은 빼기 연산
 */
