#include <stdio.h>
#include "12-3a.h"
#pragma warning(disable: 4996)

int main12_3(void) {
  int prev_mode = 0;
  int input_mode, input_distance;
  float input_oil;


  printf("유럽식 모드는 0, 미국식 모드는 1을 입력하시오: ");
  scanf("%d", &input_mode);
  while (input_mode >= 0) {
    set_mode(&prev_mode, input_mode);
    get_info(prev_mode, &input_distance, &input_oil);
    show_info(prev_mode, input_distance, input_oil);
    printf("유럽식 모드는 0, 미국식 모드는 1을 입력하시오");
    printf("(끝내려면 -1): ");
    scanf("%d", &input_mode);
  }
  printf("종료.\n");

  return 0;
}