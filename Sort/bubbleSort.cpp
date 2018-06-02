#include <iostream>

using namespace std;


int main(){
    int n, tmp;
    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){//n-1번 비교, iteration마다 맨 뒤에 i개씩 정렬 완료되므로)
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
    return 0;
}
