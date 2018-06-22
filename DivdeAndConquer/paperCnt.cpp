/*
 1780 종이의 개수
 */
#include <iostream>

using namespace std;

int a[2188][2188];
int neg_cnt = 0;
int zero_cnt = 0;
int one_cnt = 0;


void divd(int rdx, int cdx, int cnt){ // rdx x cdx을 마지막으로 하는, 한 변의 길이가 cnt인 종이
    //printf("--- idx:[%d x %d], cnt:%d ---\n", rdx, cdx, cnt);
    int tmp = a[rdx][cdx]; // 마지막 인덱스를 임시로 저장
    bool check = true;
    // 종이(다 같은지)인지 확인
    for(int i=rdx-cnt+1;i<=rdx;i++){ // 횟수 종이의 마지막 위치에서 한칸씩 반대 방향으로 check
        for(int j=cdx-cnt+1;j<=cdx;j++){
            //printf("%d ", a[i][j]);
            if(a[i][j] != tmp){
                check = false;
            }
        }
        //printf("\n");
    }
    if(check){
        if(tmp == -1){
            neg_cnt++;
        }else if(tmp == 0){
            zero_cnt++;
        }else if(tmp == 1){
            one_cnt++;
        }
        return;
    }
    int n_cnt = cnt/3; // 다음 한 변의 길이
    for(int i=0;i<3;i++){ // 행을 3등분
        for(int j=0;j<3;j++){ // 열을 3등분
           // printf("*** 호출 idx[%d x %d], cnt: %d**\n", next_cnt*i, next_cnt*j, next_cnt);
            divd(rdx-n_cnt*i, cdx-n_cnt*j, n_cnt); // 맨 마지막 위치에서 다음 한변의 길이만큼 i칸 j칸 이동
            /*
            */
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    
    divd(n, n, n); // nxn을 마지막으로 하는, 한 변의 길이가 n인 종이
    cout << neg_cnt << endl;
    cout << zero_cnt << endl;
    cout << one_cnt << endl;
    
    return 0;
}
