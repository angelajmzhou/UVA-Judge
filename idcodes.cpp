#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring> 


using namespace std;

int main(){
    char buff[100];
    int i;
    
     while(scanf("%s",buff) && buff[0]!='#'){
    int len = strlen(buff);
        if (next_permutation(&buff[0], &buff[len])){
            printf("%s\n", buff);
        } else{
            printf("No Successor\n");
        }
        memset(buff, 0, len);
    }
    return 0;
}


