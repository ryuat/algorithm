#include <iostream>
#include <algorithm>

/*
 2110
 공유기 설치
*/

using namespace std;

int a[200000];
int n, c;// n개의 집, c개의 공유기

bool check(int x){
    int cnt = 1; // 첫번째 집 설치
    int before = a[0]; // 첫번째 집의 위치
    for(int i=1;i<n;i++){
        if(a[i] - before >= x){ // 현재 위치 - 최근 공유기 설치 위치
            before = a[i]; // 현재 위치가 최근 공유기 설치 위치
            cnt++; // 설치된 공유기 수
        }
    }
    return cnt >= c; // 설치해야할 공유기를 모두 설치 했는지 여부
}

int main(){
    scanf("%d %d", &n, &c);
    
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    
    sort(a, a+n);
    int min_dist = 0; // 최소거리
    int max_dist = a[n-1]-a[0]; // 최대거리
    
    int ans = 0; // 최종결과
    while(min_dist <= max_dist){
        int mid = (min_dist + max_dist)/2;
        if(check(mid)){
            min_dist = mid+1;
            if(ans < mid){
                ans = mid;
            }
        }else{
            max_dist = mid-1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

