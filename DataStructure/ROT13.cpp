#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char input[101];
    scanf("%[^\n]s", input);
    
    int i=0;
    while(input[i] != '\0'){
        if('A' <= input[i] && input[i] <= 'Z'){
            printf("%c", (input[i] - 'A' + 13)%26 + 'A');
        }else if ('a' <= input[i] && input[i] <= 'z'){
            printf("%c", (input[i] - 'a' + 13)%26 + 'a');
        }else{
            printf("%c", input[i]);
        }
        i++;
    }
    
    return 0;
}

