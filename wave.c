#include <stdio.h>
#include <math.h>

int main(){
    int cases, amp, freq, i, j, k, digits;
    scanf("%d", &cases);
    for(i=1;i<=cases;i++){
        scanf("%d %d", &amp, &freq);
        digits = 1;
            for(j=1;j<=freq;j++){
                for(k=1;k<=amp;k++){
                    printf("%d\n", k*digits);
                    digits += pow(10,k);
                }
                digits -= pow(10,amp);

                for(k = amp-1; k>0;k--){
                    digits -= pow(10,k);
                    printf("%d\n", k*digits);
                }
                
                if(j<freq){
                   printf("\n"); 
                }
            }
        if(i<cases){
                   printf("\n"); 
        }
    }

    return 0;
}