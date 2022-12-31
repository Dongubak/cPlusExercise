#include <stdio.h>

int main11_13(int argc, char *argv[]) {
  int i;
  for (i = argc - 1; i > 0; i--) {
    printf("%s ", argv[i]);
  }

  return 0;
}