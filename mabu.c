#include <stdio.h>
#include <math.h>

int main(){
    double n,i;
    
    while (scanf("%lf", &n) && n){
        i = trunc(sqrt(n));
        if (pow(i,2) == n){printf("yes\n");}
        else{printf("no\n");}
    }
    return 0;
}