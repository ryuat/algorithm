/*
 10610
 30
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    char str[100001];

    scanf("%s", str);
    int size = (int)strlen(str);
    sort(str, str+size);
    int ans=0;
    
    for(int i=0;i<size;i++){
        ans += str[i]-'0';
        
    }
    
    if(str[0] == '0' && ans%3 == 0){
        reverse(str, str+strlen(str));
        for(int i=0;i<size;i++){
            printf("%c", str[i]);
        }
    }else{
        printf("%d\n", -1);
    }

    return 0;
}

/*
 3의 배수 특징
 각 자리의 합이 3의 배수
 
 30의 배수
 10 * 3의 배수 => 0이 존재
 */
