/*
 11399
 ATM
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n); // n번째 사람이 인출 소요시간
    vector<int> c(n); // n번째까지 누적값 배열
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // 오름차순 정렬
    
    c[0] = a[0]; // 첫번째 누적값
    int total = 0; // 누적값의 총 합
    for(int i=1;i<n;i++){
        c[i] = c[i-1] + a[i];
        total += c[i];
    }
    cout << total+c[0] << endl;
    return 0;
}
