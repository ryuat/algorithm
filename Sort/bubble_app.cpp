/*
1377 버블소트
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    
    vector<pair<int, int>> a(n);
    
    for(int i=0;i<n;i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    int max_i = 0;
    for(int i=0;i<n;i++){
        if(max_i < a[i].second - i)
            max_i = a[i].second-i;
    }
    
    printf("%d", max_i+1);
    return 0;
}


/*
 버블 소트 i,j 각각을 시뮬레이션해볼 때,
 정렬 전, 후
 앞에서 뒤로 이동할 수는 i 한 loop에 가능
 뒤에서 앞으로 이동할 수는 한 칸 이동하는 데 i 한 회전 필요.
 => 뒤에서 앞으로 이동해야할 칸의 수 최대값 i
 */
