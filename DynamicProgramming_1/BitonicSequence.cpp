#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, result = 0; // N: 원소 갯수, result: 최종결과
    cin >> N;
    vector<int> u(N+1); // u[N]: N번째가 끝점인 증가수열
    vector<int> d(N+1); // d[N]: N번째가 시작점인 감소수열
    vector<int> num(N+1); // N번째 값
    
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    
    // u[N] 채우기. u[N]: N번째 값과 비교하여 좌측의 값들이 더 작은 값이면 이어 붙인다. => 증가수열
    for(int i=1; i<=N; i++){
        u[i] = 1;
        for(int j=1; j<i; j++){
            if(num[i] > num[j] && u[i] < u[j] + 1)
                u[i] = u[j] + 1;
        }
    }
    
    // d[N] 채우기. d[N]: N번째 값과 비교하여 우측의 값들이 더 작은 값이면 이어 붙인다. => 감소수열
    for(int i=N; i>=1; i--){
        d[i] = 1;
        for(int j=i+1; j<=N; j++){
            if(num[i] > num[j] && d[i] < d[j] + 1 )
                d[i] = d[j] + 1;
        }
    }
    
    for(int i=1; i<=N; i++)
        if(result < u[i] + d[i] - 1) // i번째 끝점 증가수열, i번째 시작점 감소수열 이어 붙인다.
            result = u[i] + d[i] - 1; // 중복된 길이 1을 빼준다.

    cout << result << endl;
    return 0;
}
