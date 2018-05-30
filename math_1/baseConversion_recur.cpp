/*
 base conversion 11576 재귀
 a진법 -> 10진법 -> b진법
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
void conv(int ans, int b)
{
    if(ans == 0) return;
    conv(ans/b, b);
    cout << ans%b << " ";
}

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
    
    conv(ans, b);
    return 0;
}

