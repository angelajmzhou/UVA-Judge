#include <stdio.h>
#include <math.h>

int main() {
    int num, i, a, b;
    while(scanf("%d", &num)) {
        int lower = pow(10, num / 2);
        int upper = pow(10, num);
        
        for(i = 0; i <= sqrt(upper); i++) {
            int square = i * i;
            if(square >= upper) break;

            a = square / lower;
            b = square % lower;

            if((a + b) * (a + b) == square) {
                printf("%0*d\n", num, square);
            }
        }
    }
    return 0;
}