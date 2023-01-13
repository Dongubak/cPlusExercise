#include <stdio.h>
#pragma warning(disable: 4996)

extern void srand1(unsigned int);
extern int rand0(void);


int r_driver(void) {

  unsigned int input_seed;
  int count = 1;

  while (scanf("%u", &input_seed) == 1)
  {
    printf("--------------%d--------------\n", count++);
    srand1(input_seed);
    for (int i = 0; i < 5; i++)
    {
      printf("%6d", rand0());
    }
    printf("\n-----------------------------\n");
    
  }

  return 0;
}