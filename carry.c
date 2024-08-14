#include <stdio.h>
#include <stdlib.h>


int main(){
    int a,b,count,carry;
    while(scanf("%d %d", &a, &b) && (a||b)){
        count = 0;
        carry = 0;
         while(a||b){
            if((a % 10) + (b % 10) + carry >= 10){
                count++;
                carry = 1;
            }
            else{
                carry = 0;
            }
            a = a / 10;
            b = b / 10;
        }
        switch (count){
            case 0:
                printf("No carry operation.\n");
                break;
            case 1:
                printf("1 carry operation.\n");
                break;
            default:
                printf("%d carry operations.\n", count);
            }
    }
}