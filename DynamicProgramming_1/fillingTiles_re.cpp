#include <iostream>

using namespace std;


int d[31];

int main(void){
    int n;
    scanf("%d", &n);
    d[0] = 0;
    d[1] = 0;
    d[2] = 3;
    
    for(int i=3;i<=n;i++){
        d[i] = d[i-2]; // 가로로 1x2 타일 세 개 세우는 경우
        for(int c=1;c*2<=i;c++){ // 엇갈리게 쌓는 경우 (n이 짝수일 때마다 2가지씩)
            if(c*2 == i) // n열의 범위를 모두 활용하여 엇갈리게 쌓는 경우
                d[i] += 2; // 두 가지
            d[i] += d[i-2*c]*2;
        }
    }
    printf("%d", d[n]);
    return 0;
}






















//#include <iostream>
///*
// 놀이 공원
// 1561
// */
//using namespace std;
//
//int n, m; // 마지막n번, m개 기구
//int t[10001]; // 놀이기구의 운행시간
//int main(){
//    cin >> n >> m;
//
//    for(int i=1;i<=m;i++){
//        cin  >> t[i];
//    }
//
//    if(n <= m){
//        printf("%d\n", n); // 놀이기구가 사람수보다 많다면, 마지막 사람 번호가 마지막 사람이 탑승한 기구번호
//        return 0;
//    }
//
//    long long left = 0;
//    long long right = 2000000000LL * 30LL; // 20억명이, 30분짜리 놀이기구 1개 탈 경우 최대시간
//
//    while(left <= right){
//        long long mid = (left+right)/2;
//        long long begin=0, end=m; // 0분에 m개의 기구수만큼 m명이 탑승하면서 시작
//        int cnt = 0;
//
//        for(int i=1;i<=m;i++){
//            //printf("%lld %lld %lld\n" , mid, t[i], end);
//            end += mid/t[i]; // mid분에 탑승한 마지막 번호
//            if(mid%t[i] == 0){ // mid분에 탑승 시작된 놀이기구 번호 개수
//                cnt++;
//            }
//        }
//
//        begin = end - cnt + 1;// mid분에 탑승한 첫번째 아이의 번호
//
//        if(begin > n){
//            right = mid - 1;
//        }else if (end < n){
//            left = mid +1;
//        }else{ // 마지막 번호 n이 mid분에 탑승한 begin~end 범위에 있다면
//            for(int i=1;i<=m;i++){// 어떤 놀이기구를 탔는지 찾는다
//                if(mid % t[i] == 0){ // mid분에 i번째 기구를 탑승했고
//                    if(begin == n){ // 그 때 탑승한 아이의 번호가 마지막 번호 n이면
//                        printf("%d\n", i);
//                        return 0;
//                    }
//                    begin += 1; // 탑승한 아이의 다음 번호
//                }
//            }
//        }
//
//    }
//
//    return 0;
//}

