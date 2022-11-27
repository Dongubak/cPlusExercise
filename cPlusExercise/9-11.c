#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
  /*0 1 1 2 3 5 8*/
  int i, k, j, cur, tmp;
  cur = 1;
  k = 0;
  scanf("%d", &j);

  for (i = 0; i < j + 1; i++) {
    printf("%d ", cur);
    tmp = k;
    k = cur;
    cur = tmp + cur;
  }

  return 0;
};