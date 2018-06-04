/*
 11650 좌표 정렬(연산자오버로딩 활용)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
    bool operator < (const Point &b) const{
        if(x < b.x)
            return true;
        else if(x == b.x)
            return y < b.y;
        else
            return false;
    }
};

bool cmp(const Point &a, const Point &b){
    if(a.x < b.x)
        return true;
    else if (a.x == b.x)
        return a.y < b.y;
    else
        return false;
}

int main(void){
    
    int n;
    scanf("%d", &n);
    vector<Point> a(n);
    
    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    
    sort(a.begin(), a.end());
    
    for(int i=0;i<n;i++)
        printf("%d %d\n", a[i].x, a[i].y);
    return 0;
}
