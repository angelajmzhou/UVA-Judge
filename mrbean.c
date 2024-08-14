#include <stdio.h>
#include <stdlib.h>

int main (){

    int numcases;
    scanf("%d",&numcases);

    int i, j;
    int dim;
    int isGood;

    for (i = 1; i <= numcases; i++){
        isGood = 1;
        for (j=0; j<3; j++){
            scanf("%d", &dim);
            if (dim>20){
                isGood = 0;
            }
        }
    if (isGood) {printf("Case %d: good\n", i);}
    else {printf("Case %d: bad\n", i);}
    }
    return 0;
}
