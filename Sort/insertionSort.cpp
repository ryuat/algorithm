#include <iostream>

using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){ // i번째부터 시작하여 두 번째 항까지, 좌측값과 비교
            if(a[j-1] > a[j]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            } else break;
        }
    }

    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
