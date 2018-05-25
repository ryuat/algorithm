/*
 baekjoon 1912 연속합
 s[n]: n번째값을 끝점으로 하는 연속합
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    
    int n;
    cin >> n;
    
    vector<int> num(n);// n번째값
    vector<int> s(n); // s[n]: n번째값을 끝점으로 하는 연속합
    
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    s[0] = num[0]; // 첫번째 값
    for(int i=1; i<n; i++){
        s[i] = num[i];
        if(s[i-1] > 0) // 좌측값을 끝점으로하는 연속합이 양수이면 기준값을 더한다.
			// s[i] < s[i-1] + s[i]
            s[i] = s[i] + s[i-1];
    }
    cout << *max_element(s.begin(), s.end()) <<endl;
    return 0;
}

