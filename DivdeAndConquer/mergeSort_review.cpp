#include <iostream>

using namespace std;

int a[1000];
int b[1000];

void merge(int start, int end){
    int mid = (start + end)/2;
    int i = start, j = mid+1; // i: 이등분 후 첫번째 배열의 인덱스, j: 이등분 후 두번째 배열의 인덱스
    int k = start; // 임시 배열의 인덱스
    while(i <= mid && j <= end){ // 첫번째 배열 내의 위치를 가리킬 경우 && 두번째 배열 내의 위치를 가리킬 경우
        if(a[i] < a[j]) // 첫번째 배열의 i번째 수와, 두번째 배열의 j번째 수를 비교
            b[k++] = a[i++]; // 작은 값을 임시 배열(동일 인덱스)에 저장
        else
            b[k++] = a[j++];
    }
    // 위 while문을 벗어났을 때, 두 수열의 길이가 다를 경우, 하나의 수열은 마지막 인덱스까지 처리되지 않을 수 밖에 없다.
    // 따라서 이들을 추가로 처리해줄 필요가 있다.
    while(i <= mid){ // 첫번째 배열의 마지막 위치의 값까지 임시 배열 뒤쪽에 저장
        b[k++] = a[i++];
    }
    while(j <= end){ // 두번째 배열의 마지막 위치의 값까지 임시 배열 뒤쪽에 저장
        b[k++] = a[j++];
    }
    for(int i=start;i<=end;i++){ // 임시배열의 값을 원래 배열의 값에 저장
        a[i] = b[i];
    }
}
void divd(int start, int end){
    if(start == end) return;
    int mid = (start + end)/2;

    // 수열을 이등분하고, 등분된 두 수열을 합친다.
    divd(start, mid); // 시작 항부터 중간 항까지
    divd(mid+1, end); // 중간항 다음 항부터 마지막 항까지
    merge(start, end); // 시작 항부터 마지막 항까지(등분되기 전의 길이만큼) 이등분 후 합친다.
}
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    divd(0, n-1);
    
    for(int i=0;i<n;i++){
        cout << a[i]<< ' ';
    }
    
    return 0;
}
