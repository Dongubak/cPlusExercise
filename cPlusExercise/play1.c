#include <stdio.h>

void st_vo(void) {
  static int a = 10;
  printf("%d", ++a);
}