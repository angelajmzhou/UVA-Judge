#include <stdio.h>
#include <math.h>

int main(){
    int n,i,output;
    while(scanf("%d", &n) && n != 0){
        output = n*(n+1)*(2*n+1)/6;
        printf("%d\n", output);
    }
    return 0;
}