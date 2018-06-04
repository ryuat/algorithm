/*
11650 좌표 정렬(pair 활용)
 */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    
    vector<pair<int, int>> a(n);
    
    for(int i=0;i<n;i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++)
        printf("%d %d\n", a[i].first, a[i].second);

    return 0;
}
