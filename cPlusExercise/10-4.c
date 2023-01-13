#include <stdio.h>
#include <stdlib.h>

int get_biggest_index(const double*, const double*);

int main10_4(void) {
  double numbers[10];
  int iter; 
  
  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++)
    printf("numbers[%d] : %.1lf\n", iter, numbers[iter] = rand() * 0.1);

  printf("the index of the most biggest number : %d\n", get_biggest_index(numbers, numbers + sizeof(numbers) / sizeof(double)));

  return 0;
}

int get_biggest_index(const double*pt, const double*end_pointer)
{
  const double* const st_pt = pt;
  double upper_double = *pt;
  int upper_index = 0;///upper_index is the index of the most biggest number.

  do {
    if (*pt > upper_double) {
      upper_double = *pt;
      upper_index = pt - st_pt;
    }
  } while (++pt < end_pointer);

  return upper_index;
}
