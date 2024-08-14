#include <stdio.h>

int findNum(int num);

int main() {
     int i, j, low, high, len, maxLen, n;

  while (scanf("%d %d", &i, &j) > 0) {
    if (i > j) {
      high = i;
      low = j;
    } else {
      high = j;
      low = i;
    }

    maxLen = 0;
    for (n = low; n <= high; ++n) {
      len = findNum(n);
      if (len > maxLen) {
        maxLen = len;
      }
    }
    printf("%d %d %d\n", i, j, maxLen);
  }
  return 0;
}

int findNum(int num) {
    int count = 1;
    int n = num;
    while (n > 1) {
        if (n&1) {
            n = (3 * n) + 1;
        } else {
            n= n>>1;
        }
        count++;
    }
    return count;
}

