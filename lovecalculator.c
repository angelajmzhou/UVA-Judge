#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sumcalc(int sum) {
    if (sum == 0) {
        return 0;
    }
    if (sum % 9 == 0) {
        return 9;
    }
    return sum % 9;
}

int main() {
    char name1[26];
    char name2[26];
    int i;

    int sum1, sum2;
    while (scanf(" %[^\n] %[^\n]", name1, name2) == 2) {
        sum1 = 0;
        sum2 = 0;
        for (i = 0; i < strlen(name1); i++) {
            if (islower(name1[i])) {
                sum1 += name1[i] - 'a' + 1;
            } else if (isupper(name1[i])) {
                sum1 += name1[i] - 'A' + 1;
            }
        }
        for (i = 0; i < strlen(name2); i++) {
            if (islower(name2[i])) {
                sum2 += name2[i] - 'a' + 1;
            } else if (isupper(name2[i])) {
                sum2 += name2[i] - 'A' + 1;
            }
        }

        sum1 = (sum1%9)?sum1%9:9;
        sum2 = (sum2%9)?sum2%9:9;

        if (sum1 >= sum2) {
            printf("%.2f %%\n", 100.0 * ((double)sum2) / ((double)sum1));
        } else {
            printf("%.2f %%\n", 100.0 * ((double)sum1) / ((double)sum2));
        }
    }
    return 0;
}
