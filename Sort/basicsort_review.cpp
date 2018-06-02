#include <iostream>

using namespace std;
int a[100];
int tmp;

void bubble(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void selection(int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]){
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}
void insertion(int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(a[j] < a[j-1]){
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            } else {
                break;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)
        cin >> a[i];

    //bubble(n);
    //selection(n);
    insertion(n);
    
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
