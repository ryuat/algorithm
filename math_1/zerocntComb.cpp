/*
 2004 조합 0의 개수
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, ans_5 = 0, ans_2=0;
    
    cin >> n >> m;
    
    for(long long i=5;i<=n;i*=5)
        ans_5 += n/i;
    
    for(long long i=5;i<=n-m;i*=5)
        ans_5 -= (n-m)/i;
    
    for(long long i=5;i<=m;i*=5)
        ans_5 -= m/i;
    
    for(long long i=2;i<=n;i*=2)
        ans_2 += n/i;
    
    for(long long i=2;i<=n-m;i*=2)
        ans_2 -= (n-m)/i;
    
    for(long long i=2;i<=m;i*=2)
        ans_2 -= m/i;
    
    cout << min(ans_2, ans_5);
    
    return 0;
}

/*
 조합에서는 분자에서 10을 나눠주므로, 2의개수가 5의개수보다 적어질 수 있다.
 따라서 2의 개수와 5의 개수를 모두 세야 한다.
*/
