/*
11651 좌표 정렬2 y를 우선순위로 정렬
 */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Point{
    int x, y;
    bool operator < (const Point &b) const {
        if(y < b.y)
            return true;
        else if(y==b.y)
            return x < b.x;
        else
            return false;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    
    vector<pair<int, int>> a(n);
    
    for(int i=0;i<n;i++)
        scanf("%d %d", &a[i].second, &a[i].first);
    
    sort(a.begin(), a.end());

    for(auto &p: a) // 참조자 p는 a
        printf("%d %d\n", p.second, p.first);

    return 0;
}
