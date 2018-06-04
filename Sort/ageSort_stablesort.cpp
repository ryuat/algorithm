/*
10814 나이순 정렬 stable_sort, 람다함수 활용
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    
    vector<pair<int, string>> a(n);
    
    for(int i=0;i<n;i++)
        cin >> a[i].first >> a[i].second;
    
    stable_sort(a.begin(), a.end(), [](pair<int,string> a, pair<int,string> b){
        return a.first < b.first;
    });

    for(auto &p: a)
        cout << p.first << " "<< p.second << "\n";

    return 0;
}
