#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void gen_random(int* pt) {
  srand((unsigned int)time(0));
  for (int i = 0; i < MAX; i++) {
    *(pt + i) = (rand() % 10) + 1;
  }
}

int main12_5(void) {
  int* pt = (int*)malloc(sizeof(int) * MAX);
  
  gen_random(pt);
  
  for (int i = 0; i < MAX; i++) {
    printf("[%2d] : %2d  ", i, pt[i]);
    i % 10 == 9 && i != 0 ? printf("\n") : NULL;
  }

  for (int left = 0; left < MAX - 1; left++) {
    for (int right = left + 1; right < MAX; right++) {
      if (pt[left] < pt[right]) {
        int tmp = pt[right];
        pt[right] = pt[left];
        pt[left] = tmp;
      }
    }
  }

  printf("                                                     Á¤·Ä ÈÄ\n");

  for (int i = 0; i < MAX; i++) {
    printf("[%2d] : %2d  ", i, pt[i]);
    i % 10 == 9 && i != 0 ? printf("\n") : NULL;
  }

  free(pt);
  return 0;
}