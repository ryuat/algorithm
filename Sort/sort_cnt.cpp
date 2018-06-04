/*
 10989 수 정렬하기 3
 메모리 제한 8mb
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n, num;
    scanf("%d", &n);
    
    vector<int> cnt(10001); // 최대값 10000, cnt[i] = i의 갯수
    
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        cnt[num] += 1;
    }
    
    for(int i=1;i<=10000;i++){
        for(int j=0;j<cnt[i];j++){
            printf("%d\n", i);
        }
    }
    return 0;
    
}
/*
 
 N이 천만개까지 주어진다.
 기존 sort방식을 활용하면 배열을 천만개 만들어야 한다.
 int 배열 천만개 => 4byte * 10,000,000 = 40,000,000 bytes = 약 40mb
 메모리 초과
 
 따라서, 다른 방식을 생각해야 한다.
 문제 조건을 보면, 입력받을 수 있는 숫자의 범위가 1~10000이므로
 1000개의 배열을 만들어 해당 숫자가 몇개 입력되었는지 확인하는 방법을 활용
 */
