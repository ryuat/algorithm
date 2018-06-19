/*
 1201
 nmk
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    if (m+k-1 <= n && n <= m*k) {
        for (int i=0; i<n; i++) {
            a[i] = i+1;
        }
        vector<int> g;
        g.push_back(0);
        g.push_back(k);
        n-= k; // k개의 원소를 가진 그룹을 한개 만들기 위한 인덱스
        m--; // k개의 원소를 가진 그룹 하나를 만들었으므로 앞으로 만들어야 할 그룹은 m-1
        
        int g_k = m==0 ? 1 : n/m; // 한 그룹을 제외한 n개로 m개의 그룹을 만들려면 g_k개수 만큼 가진 그룹을 만들어야 한다.
        int r = m==0 ? 0:n%m; // g_k개수를 가진 그룹을 m개 만들면, r개가 남는다.
        
        for(int i=0;i<m;i++){
            g.push_back(g.back() + g_k + (r>0? 1:0)); // 첫번째 그룹 마지막 인덱스부터, g_k개 + r만큼 그룹 생성
            r > 0 ? r--:r;
        }
        
        for(int i=0;i<g.size()-1;i++){
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        }
        
        for (int i=0; i<a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}
