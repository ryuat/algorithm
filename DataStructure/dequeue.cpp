#include <iostream>
#include <string.h>
using namespace std;

int arr[20002]; // 모두 push front or back => 1만개 앞뒤로
int front = 10000; // 배열 가운데에 위치 (다음 front idx)
int back = 10001; // 배열 가운데에 위치 (다음 back idx)


int main(){
    int N;
    scanf("%d", &N);
    
    char op[11];
    int val;
    for(int i=0;i<N;i++){
        scanf("%s", op);
        if(!strcmp(op, "push_front")){
            scanf("%d", &val);
            arr[front--] = val; // front idx 이동
        }else if(!strcmp(op, "push_back")){
            scanf("%d", &val);
            arr[back++] = val;
        }else if(!strcmp(op, "pop_front")){
            if(back-front-1 > 0){
                printf("%d\n", arr[++front]); // front를 우측으로 이동 후 출력
            }else{
                printf("%d\n", -1);
            }
        }else if(!strcmp(op, "pop_back")){
            if(back-front-1 > 0){
                printf("%d\n", arr[--back]); // back을 좌측으로 이동 후 출력
            }else{
                printf("%d\n", -1);
            }
        }else if(!strcmp(op, "size")){
            printf("%d\n", back-front-1);
        }else if(!strcmp(op, "empty")){
            printf("%d\n", back-front-1>0? 0:1);
        }else if(!strcmp(op, "front")){
            printf("%d\n", back-front-1>0?arr[front+1]:-1);
        }else if(!strcmp(op, "back")){
            printf("%d\n", back-front-1>0?arr[back-1]:-1);
        }
    }
    
    return 0;
}

