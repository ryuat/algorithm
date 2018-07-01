#include <iostream>
#include <vector>
#include <algorithm>
/*
 2261
 가장 가까운 두 점
 */
using namespace std;

struct Point{
    int x, y;
    bool operator < (const Point &p) const{
        if(x == p.x){
            return y < p.y;
        }else{
            return x < p.x;
        }
    }
};
int dist(const Point &p1, const Point &p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int brute_force(const vector<Point> &a, int s, int e){
    int ans = -1, d;
    for(int i=s;i<e;i++){
        for(int j=i+1;j<=e;j++){
            d = dist(a[i], a[j]);
            if(ans == -1 || d < ans){
                ans = d;
            }
        }
    }
    return ans;
}

bool cmp(const Point &p1, const Point &p2){
    return p1.y < p2.y;
}
int solve(const vector<Point> &a, int s, int e){ // vector, start, end
    int n = e-s+1; // 점의 개수
    if(n<=3){
        return brute_force(a, s, e); // 모든 점에 대해 거리 계산 시도하여 최단거리 찾기
    }
    int mid = (s+e)/2;
    int d_left = solve(a, s, mid); // 좌측 최단거리
    int d_right = solve(a, mid, e); // 우측 최단거리
    int ans = min(d_left, d_right);
    
    vector<Point> b;
    for(int i=s;i<e;i++){
        int dx = a[i].x - a[mid].x;
        if(dx*dx < ans){ // x축 조건 만족 -> 거리 계산 후보
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end(), cmp); // y 좌표 오름차순 정렬
    int cnt = b.size();
    for(int i=0;i<cnt-1;i++){
        for(int j=i+1;j<cnt;j++){
            int dy = b[j].y - b[i].y;
            if(dy*dy < ans){ // 후보 중 y조건 만족하면
                int d = dist(b[i], b[j]);
                if(d < ans){
                    ans = d;
                }
            }else{ // 후보들은 y조건으로 정렬되었으므로
                break;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<Point> a(n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a.begin(), a.end());
    cout << solve(a, 0, n-1) << endl; // a배열 idx (0, n-1) 범위 특정 두 점의 최단거리
    return 0;
}
/*
 1. 거리계산을 모든 점에 대해 시도해볼만한 개수(여기선 3개)를 포함할 때까지 x좌표 기준으로 분할
 2. 3개 이하의 점을 포함할 때 모든 점 간의 거리를 계산하여 최단거리 확인
 3. 분할되기 전 구역의 중앙(점)에 대해 x축 y축으로 위에서 구한 최단거리의 길이를 갖는 직사각형을 형성
 4. 해당 직사각형 모서리 내에 존재하는 모든 점에 대해 거리를 계산하여 분할 전 구역 내 최단거리 확인
*/

