/*
 1744
 수 묶기
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> pos; // 양수 배열
vector<int> neg; // 음수 배열
int one_cnt = 0; // 1의 개수
int zero_cnt = 0; // 0의 개수

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        if(x>1){
            pos.push_back(x);
        }else if(x<0){
            neg.push_back(x);
        }else if(x==0){
            zero_cnt++;
        }else{
            one_cnt++;
        }
    }
    
    sort(pos.begin(), pos.end()); // 정렬
    reverse(pos.begin(), pos.end()); // 내림차순
    sort(neg.begin(), neg.end()); // 음수 오름차순
    
    if(pos.size()%2 == 1){ // 양수의 개수가 홀수이면
        pos.push_back(1);
    }
    if(neg.size()%2 == 1){ // 음수 개수가 홀수이면
        neg.push_back(zero_cnt? 0 : 1); // 0이 존재할 경우 0을 곱하고 없을 경우 그대로 뺀다
    }
    int ans = one_cnt; // 1의 개수, 1은 곱하기 보다 더해야 최대값이 되므로
    for(int i=0;i<pos.size();i+=2){
        ans += pos[i] * pos[i+1];
    }
    for(int i=0;i<neg.size();i+=2){
        ans += neg[i] * neg[i+1];
    }
    
    printf("%d\n", ans);
    return 0;
}

/*
양수 큰 수끼리 곱하고
음수 작은 수끼리 곱

1은 더하고
0은 음수 짝이 모자랄 경우(홀수개) 남은 음수 하나를 없애는 용도로 활용
*/
