/* 양방향 그래프 인접리스트로 표현하기 */

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> a[10];
    
    for(int i=0;i<m;i++){
        int u, v, w;
        scanf("%d %d %d2", &u, &v, &w);
        a[u].push_back(make_pair(v, w)); a[v].push_back(make_pair(u, w));
    }
    
    return 0;
}
