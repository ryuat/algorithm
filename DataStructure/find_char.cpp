#include <iostream>
#include <string.h>
using namespace std;

int a[27];
char input[101];

int main(){
    scanf("%s", input);
    
    for(int i=0;i<26;i++){
        a[i] = -1;
    }
    
    int j=0;
    while(input[j] != '\0'){
        if(a[input[j]-'a']== -1){
            a[input[j]-'a'] = j;
        }
        j++;
    }
    
    for(int i=0;i<26;i++){
        printf("%d ", a[i]);
    }
    return 0;
}

