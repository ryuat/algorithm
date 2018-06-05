/*
11652 카드
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    
    vector<long long> a(n);
    
    for(int i=0;i<n;i++)
        scanf("%lld", &a[i]);
    
    sort(a.begin(), a.end()); // 오름차순 정렬
    
    long long ans = a[0];
    int cnt = 1, ans_cnt = 1;
    for(int i=1;i<n;i++){ // 6: 1 2 1 2 1 2 => 1 1 1 2 2 2 /// 3:1 2 3
        if(a[i] == a[i-1]){ // 정렬된 배열을 순회하면서, 해당 인덱스까지 동일한 숫자가 몇번 나왔는지
            cnt += 1; // 이전 값과 같다면 갯수 추가
        }else{
            cnt = 1; // 이전 값과 다르다면 1개로 초기화
        }
        
        if(ans_cnt < cnt){ // 현재까지의 최대 cnt와 ans 저장
            ans_cnt = cnt;
            ans = a[i];
        }
    }
    
    cout << ans << "\n";
    return 0;
}
/*
 입력 받고 정렬 후 갯수 세기
 */
