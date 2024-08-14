#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int a, int b){
    return a<b? a : b;
}
int main(){
    int pg;
    int i, v, x, l, c;
    int counter;
    int digits[10] = {0,1,2,3,4,5,6,7,8,9};
    int rem[5] = {0,1,2,3,1};
    while(scanf("%d", &pg)&&(pg!=0)){
        c = (pg-89) > 0 ? (pg-89) : 0;
        l = (pg>49) ? (min(pg, 89) -39) : 0;
        x = 0;
        for (counter = 8; (counter<=(pg-10) && counter < 99); counter += 10){
            /*8-18,18-28,28-38*/
            /*38-48*/
            /*58-68,68-78,78-88*/
            x+= rem[((counter/10)+1)%5]*10;
        }
        /*printf("counter: %d x thus far: %d\n", counter, x);*/
        int inc;
        for (inc = 0; inc<(pg-(counter)) && counter< 98; inc++){
            x+=rem[((counter/10)+1)%5];
        }
        if (pg >= 39) {x+=3;}
        if (pg >=49) {x+=2;}
        if (pg >= 89) {x+= 3;}
        if (pg >= 99) {x+=2;}

        v = 0;
        for (counter = (pg/10); counter>0; counter--){
            v+=5;
        }
        counter = pg%10;
        if (counter == 9){counter = 8;}
        for (; counter>=4; counter--){
            v+=1;
        }        
        i=0;
        for (counter = (pg/10); counter>0; counter--){
            i+=14;
        }
        for (counter = pg%10; counter>0; counter--){
            i+=rem[(counter%5)];
        }
        /*gets the last set of pages 0-9*/
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", pg, i, v, x, l, c);
    }  
    return 0;
}