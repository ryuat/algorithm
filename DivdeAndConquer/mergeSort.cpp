/*
 merge sort
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

void merge(int start, int end){
    int mid = (start + end)/2;
    int i = start; int j = mid+1;
    
    vector<int> b;
    
    while(i <= mid && j <= end){
        if(a[i] < a[j]){
            b.push_back(a[i++]);
        }else{
            b.push_back(a[j++]);
        }
    }
    while(i <= mid){
        b.push_back(a[i++]);
    }
    while(j <= end){
        b.push_back(a[j++]);
    }
    for(int i=0;i<b.size();i++){
        a[start++] = b[i];
    }
    cout << endl;
}

void divd(int start, int end){
    if(start == end ){
        return;
    }
    int mid = (start + end)/2;
    divd(start, mid);
    divd(mid+1, end);
    merge(start, end);
    
}
int main(void){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int val;
        cin >> val;
        a.push_back(val);
    }
    divd(0, t);
    
    for(int i=0;i<a.size();i++){
        cout << a[i] << ' ';
    }
    return 0;
}
