#include <stdio.h>
#include <stdlib.h>

int main(){
    long int sn1, sn2,diff;
    while(scanf("%ld %ld", &sn1, &sn2)!=EOF){
        diff = labs(sn1-sn2);
        printf("%ld\n", diff);
    }
    return 0;
}