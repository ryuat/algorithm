/*
baekjoon 1212 8진수 2진수 변환 리뷰
8진수 한자리를 2진수 세자리로
 */
#include <iostream>
#include <string>

using namespace std;

string octal[8] = {"000","001","010","011","100","101","110","111"}; // 8진수 한자리 => 2진수 세자리

int main(void){
    
    string s;
    cin >> s;
    
    for(int i=0;i<s.size();i++){
        int x = s[i] - '0';
        if(i==0 && x<4){ // 8진수의 첫자리이면서 4보다 작은 경우
            if(x==0){
                cout << "0";
            } else if(x==1){
                cout << "1";
            } else if(x==2){
                cout << "10";
            } else if(x==3){
                cout << "11";
            }
        }else{ // 8진수의 첫자리가 아니거나 4보다 큰 경우
            cout << octal[x]; // 8진수 한자리를 2진수 세자리로 그대로 매핑한다.
        }
    }
    cout << endl;
    return 0;
}
