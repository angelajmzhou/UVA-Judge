#include <stdio.h>
#include <math.h>

int main(){
    int num, n, count,i;
    while(scanf("%d", &num) && num){
        count=0;
        n=num;
        
        if (!(n%2)){count++;}
        while(!(n%2)){
            n = n>>1;
        }
        /*number now odd, take care of odd prime factors*/
        for (i=3; i<= sqrt(n); i+=2){
            if(!(n%i)){count++;}
            while(!(n%i)){
                n=n/i;
            }
        }
        printf("%d : %d\n", num, count);
    }
    return 0;
}