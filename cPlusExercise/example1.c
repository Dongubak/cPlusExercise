#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct {
  int student_number;
  float height;
  float weight;
} student;

void clear_buf(void) {
  while (getchar() != '\n') {
    continue;
  }
}

int mainexmaple_1(void) {
  student* pt = (void*)0;
  int input_number = 0;
  int i = 0;
  float avg_height = 0.;
  float avg_weight = 0.;
  scanf("%d", &input_number);
  clear_buf();
  pt = (student*)malloc(sizeof(student) * input_number);
  for (i = 0; i < input_number; i++) {
    scanf("%d", &((pt + i)->student_number));
    scanf("%f", &((pt + i)->height));
    scanf("%f", &((pt + i)->weight));
    clear_buf();
  }

  for (i = 0; i < input_number; i++) {
    avg_height += pt[i].height;
    avg_weight += pt[i].weight;
  }

  avg_height /= input_number;
  avg_weight /= input_number;

  printf("%.1f %.1f\n", avg_height, avg_weight);
  for (i = 0; i < input_number; i++) {
    printf("%d ", (pt + i)->student_number);
    if ((pt + i)->height >= avg_height && (pt + i)->weight >= avg_weight) {
      printf("super\n");
    }
    else if ((pt + i)->height >= avg_height || (pt + i)->weight >= avg_weight) {
      printf("average\n");
    }
    else {
      printf("below\n");
    }
  }

  free(pt);

  return 0;
}