#include <stdio.h>
#include <stdlib.h>

double sub_big_small(const double*, const double*);

int main10_5(void) {
  double numbers[10];
  int iter;

  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++)
    printf("numbers[%d] : %.1lf\n", iter, numbers[iter] = rand() * 0.1);

  printf("the difference between the most biggest number and the most smallest number : %.1lf", sub_big_small(numbers, numbers + sizeof(numbers) / sizeof(double)));

  return 0;
}

double sub_big_small(const double*pt, const double* end_pointer)
{
  double* pair_upper_lower;
  pair_upper_lower = (double[2]){ pt[0], pt[0] };
  do {
    pair_upper_lower[0] = *pt > pair_upper_lower[0] ? *pt : pair_upper_lower[0];
    pair_upper_lower[1] = *pt < pair_upper_lower[1] ? *pt : pair_upper_lower[1];
  } while (++pt < end_pointer);
  printf("Most biggest number is %.1lf\nMost smallest number is %.1lf\n", pair_upper_lower[0], pair_upper_lower[1]);

  return pair_upper_lower[0] - pair_upper_lower[1];
}