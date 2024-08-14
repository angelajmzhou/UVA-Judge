#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
    char c;
    bool qt=1;

    while(scanf("%c",&c)!=EOF){
        if(c=='"'){
            if(qt) printf("``");
            else printf("''");
            
            qt=(!qt);
        }else printf("%c",c);
    }

    return 0;
}
