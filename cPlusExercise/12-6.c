#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

int main12_6(void) {
  
  /*for (int i = 0; i < 10; i++) {
    printf("%d", number[i]);
  }*/


  for (int i = 0; i < 10; i++) {
    char number[10] = {0};
    unsigned int input_seed;
    scanf("%ud", &input_seed);
    /*srand((unsigned int)time(0));*/
    srand(input_seed);
    for (int j = 0; j < 100; j++) {
      number[rand() % 10] += 1;
    }
    printf("                                %d번째 실행\n", i + 1);
    for (int i = 0; i < 10; i++) {
      printf("%2d의 개수 : %2d ", i + 1, number[i]);
      (i + 1) % 5 == 0 && i != 0 ? printf("\n") : NULL;
    }
    printf("\n");
  }

  return 0;
}