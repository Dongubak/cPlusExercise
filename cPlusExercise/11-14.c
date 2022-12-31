#include <stdio.h>
#include <stdlib.h>

int main11_14(int argc, char *argv[]) {
  int i;
  double result = 1;
  for (i = 0; i < atoi(argv[2]); i++) {
    result *= atof(argv[1]);
  }
  printf("%.1f", result);
  return 0;
}