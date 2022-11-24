#include <stdio.h>
#pragma warning(disable: 4996)

void interchange(int u, int v);

int main_play1(void) {
  int x = 5, y = 10;

  printf("교환 전 : x = %d, y = %d\n", x, y);
  interchange(x, y);
  printf("교환후 : x = %d, y = %d\n", x, y);

  return 0;
}

void interchange(int u, int v) {
  int temp;

  temp = u;
  u = v;
  v = temp;
}