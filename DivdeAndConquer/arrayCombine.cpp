/*
 11728
 배열합치기
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;

    vector<int> a(n); // 첫번째 배열
    vector<int> b(m); // 두번째 배열
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    // merge
    int a_idx=0, b_idx=0;
    vector<int> ans;
    
    for(int i=0;i<n+m;i++){
        if(a_idx >= n){ // 첫번째 배열의 인덱스가 배열 크기를 초과하면
            ans.push_back(b[b_idx++]); // 두번째 배열이 남았다는 의미이므로, 두번째 배열을 결과 배열에 추가
        } else if(b_idx >= m){ // 위와 반대일 경우, 첫번째 두번째 반대로
            ans.push_back(a[a_idx++]);
        } else {
            if(a[a_idx] < b[b_idx]){ // 첫번째 배열의 값과 두번째 배열의 값 중 작은 값을 결과 배열에 추가
                ans.push_back(a[a_idx++]);
            }else{
                ans.push_back(b[b_idx++]);
            }
        }
    }
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
