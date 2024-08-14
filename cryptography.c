#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int main (){
    int n;
    mpz_t p;
    while(scanf("%d\n%d", &n,&p)){
        if (n==2) {printf("%d\n",(int)sqrt(p));}
        else if (!n%2) {
            int root;
            for(root = n; n>=0; n-=2){
                root = sqrt(root);
            }
           printf("%d\n",(int)sqrt(p));
        }
        else{
            printf("%d\n", (int)pow(p,1.0/n));
        }
    }
    return 0;
}