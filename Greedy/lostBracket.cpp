/*
 1541 잃어버린 괄호
 */
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string a;
    cin >> a;

    int ans = 0; // 결과값
    int sign = 1; // 부호
    int ans_i = 0; // 항
    for(int i=0;i<a.size();i++){
        if('0'<=a[i] && a[i]<='9'){
            ans_i = a[i]-'0' + ans_i*10; // 숫자이면
        }else{ // 문자 나오면 최종결과값에 더하고 새로운 숫자 시작
            ans += sign*ans_i;
            //cout << i << "번째 "<< ans_i << endl;
            ans_i = 0;
            if(a[i] == '-' && sign == 1){
                sign = -1; // -나온 시점부터 계속 빼기 연산
            }
        }
    }
    ans += sign*ans_i; // 마지막 항 연산
    cout << ans << endl;
    return 0;
}

/*
 -가 나온 항의 뒷부분은 부호에 관계없이 뺀다.
 */
