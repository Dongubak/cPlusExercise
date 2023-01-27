#include <stdio.h>
#include <stdlib.h>

int get_biggest_element(const int*, const int*);

int main10_3(void) {
  int numbers[10];
  int iter = 0;
  ///upper_int is bigger than previous value;

  for (iter = 0; iter < sizeof(numbers) / sizeof(int); iter++) {
    printf("numbers[%d] : %d\n", iter, numbers[iter] = rand());
  }

  printf("Most biggest number is %d\n", get_biggest_element(numbers, numbers + sizeof(numbers) / sizeof(int)));

  return 0;
}

int get_biggest_element(const int*pt, const int*pointer_end)
{
  int upper_int = *pt;


  do {
    upper_int = *pt > upper_int ? *pt : upper_int;
  } while (++pt < pointer_end);

  return upper_int;
}
