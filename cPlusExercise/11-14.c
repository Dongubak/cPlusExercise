#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int* argv_d = (int*)malloc(sizeof(int) * (argc - 1));
  int i;
  double result = 1;
  
  for (i = 1; i < argc; i++) 
    argv_d[i - 1] = atoi(argv[i]);

  for (i = 0; i < argv_d[1]; i++)
    result *= argv_d[0];

  printf("%.1f", result);

  free(argv_d);
  return 0;
}