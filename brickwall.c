#include <stdio.h>
#include <math.h>

int main(){
    int len, bricks;
    while(scanf("%d", &len) && len){
        len++;
        bricks = (pow((1+sqrt(5))/2,len) - pow((1-sqrt(5))/2,len))/sqrt(5);
        printf("%d\n", bricks);
    }
    return 0;
}
