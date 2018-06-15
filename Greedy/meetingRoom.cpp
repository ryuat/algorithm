/*
 1931
 회의실 배정
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct Time
{
    int from, to;
};
bool cmp(const Time t1, const Time t2){
    if(t1.to == t2.to){
        return t1.from < t2.from;
    }
    return t1.to < t2.to;
}
int main(){
    int n;
    cin >> n;

    vector<Time> a(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i].from >> a[i].to;
    }
    sort(a.begin(), a.end(), cmp);
    
    int ans = 1;
    int end = a[0].to; // 현재 진행 중인 회의의 끝나는 시간
    for(int i=1;i<n;i++){
        if(a[i].from >= end){ // 다음 회의시간의 시작시간이 현재 진행 중인 회의이 끝나는 시간보다 뒤라면
            ans++; // 배정
            end = a[i].to; // 현재 진행 중인 회의의 끝나는 시간을 갱신
        }
    }
    
    cout << ans << '\n';
    return 0;
}

/*
 정렬 문제
 끝나는 시간을 기준으로 정렬, 끝나는 시간이 같은 경우 시작시간이 더 이른 순으로 정렬
 */
