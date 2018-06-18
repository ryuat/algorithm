/*
 1783
 병든 나이트
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int min(int val1, int val2){
    return val1<val2? val1:val2;
}
int main(){

    int h,w;
    scanf("%d %d", &h, &w);
    
    if(h==1){ // 세로가 1이면, 움직일 수 없으므로 제자리 한 칸
        printf("%d\n", 1);
    }else if(h==2){ // 세로가 2이면 2,3번 방법 반복하는 방법 활용. 최대 4칸 이동
        printf("%d\n", min((w+1)/2,4));
    }else{
        if(w<7){ // 세로가 3 이상이면서 가로가 7보다 작으면, 1,4방법 활용 최대 4칸 이동
            printf("%d\n", min(w,4));
        }else{ // 세로가 3 이상이면서 가로가 7이상일 경우, 최대 너비-2만큼 방문 가능
            printf("%d\n", w-2);
        }
    }
    
    return 0;
}
