#include <iostream>
#include <vector>
#include <utility>
/*
 놀이공원(시간초과)
 1561
 */
using namespace std;

vector<pair<int,int>> a; // 기구에 탄 아이번호, 남은 시간
vector<int> t; // 각 기구의 운행 시간

int main(){
    a.push_back(make_pair(-1,-1)); // a[0] 쓰레기값 입력
    t.push_back(-1);
    int n, m;
    int child_num = 1; // 아이의 번호
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<m;i++){ // 놀이기구에 기본 시간 입력
        int time;
        scanf("%d", &time);
        t.push_back(time);
    }
    
    for(int i=1;i<=m;i++){
        a[i].first = child_num++; // i번 기구에 아이 탑승
        a[i].second = t[i]; // i번 기구의 시간 운행시간 초기화
    }
    while(true){
        for(int i=1;i<=m;i++){
            //printf("놀이기구:%d, 대기중인아이번호:%d, 남은시간:%d\n", i, child_num, t[i]);
            if(a[i].second == 0){
              //  printf("**탑승** 놀이기구:%d, 아이번호:%d, 남은시간:%d\n", i, child_num, a[i].second);
                if(child_num == n){ // 마지막 아이일 경우
                    printf("%d", i);
                    return 0;
                }
                
                a[i].first = child_num++; // i번 기구에 아이 탑승
                a[i].second = t[i]; // i번 기구의 시간 운행시간 초기화
            }
            a[i].second -= 1; // i번 기구의 1분 운행 후 남은 시간
        }
    }
    return 0;
}
