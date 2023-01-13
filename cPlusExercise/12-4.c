#include <stdio.h>

int test_4(void) {
  static int count = 0;
  ++count;

  return count;
}

int main12_4(void) {
  printf("i : count\n");
  for (int i = 0; i < 5; i++) {
    printf("%d :   %d\n", i, test_4());
  }

  return 0;
}