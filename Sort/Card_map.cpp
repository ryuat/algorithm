/*
11652 카드
map 활용
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    
    map<long long, int> a;

    while(n--){
        long long x;
        scanf("%lld", &x);
        a[x] += 1; // a[x] = x값이 입력된 횟수
    }
    
    int ans_cnt = 0;
    long long ans=0;

    for(auto &p : a){
        if(p.second > ans_cnt){
            ans_cnt = p.second;
            ans = p.first;
        }else if(p.second == ans_cnt && ans > p.first){
            ans = p.first;
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
 입력 받고 map(key:cnt) 활용
 */
