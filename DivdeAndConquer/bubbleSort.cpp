#include <iostream>
/*
 1517
 버블소트
 */
int a[500000];
int b[500000];

long long solve(int start, int end){
    if(start == end) return 0; // 머지 대상이 한 개일 경우, 0
    
    //printf("solve(%d, %d)\n", start, end);
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;
    int k = 0;
    
    long long ans = solve(start, mid) + solve(mid+1, end);
    
    while(i <= mid && j <= end){
        //printf("(%d > %d) ? mid:%d true => %d \n", a[i], a[j],mid, mid-i+1);
        if(a[i] > a[j]){ // 뒷쪽 배열의 비교 대상 값의 크기가 클 경우
            b[k++] = a[j++];
            ans += (long long)(mid-i+1); // 앞쪽 배열의 원소 수 만큼
        }else{
            b[k++] = a[i++];
        }
    }
    while(i <= mid){
        b[k++] = a[i++];
    }
    while(j <= end){
        b[k++] = a[j++];
    }
    for(int i=start;i<=end;i++){
        a[i] = b[i-start];
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    
    long long result = solve(0,n-1); // 0부터 n-1까지 버블소트 swap 횟수
    printf("%lld\n", result);
    
    return 0;
}
/*
 i<j, a[i] > a[j] 일 경우
 i배열의 남은 개수만큼 더해준다.
 
 자신보다 앞의 있는 수 중 큰 수들의 개수의 합
 */
