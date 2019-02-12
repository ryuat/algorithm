#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void){
    int num, b, r;
    string ans="";
    
    scanf("%d %d", &num, &b);


    while(num != 0){
        r = num%b;
        
        if(r >= 10){
            ans += r + 'A' - 10;
        }else{
            ans += r + '0';
        }
        num /= b;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}
