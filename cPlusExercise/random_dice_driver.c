#include <stdio.h>
#pragma warning(disable: 4996)

unsigned short random_dice(unsigned short area_count);
void change_seed(unsigned int input_seed);

int random_dice_driver(void) {

  unsigned int input_seed;

  while (scanf("%d", &input_seed) == 1) {
    change_seed(input_seed);
    for (int i = 0; i < 5; i++)
    {
      printf("%hu  ", random_dice(6));
    }

    printf("\n");
  }

  return 0;
}