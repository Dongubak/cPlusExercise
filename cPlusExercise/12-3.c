#include <stdio.h>
#include "12-3a.h"
#pragma warning(disable: 4996)

int main12_3(void) {
  int prev_mode = 0;
  int input_mode, input_distance;
  float input_oil;


  printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ�: ");
  scanf("%d", &input_mode);
  while (input_mode >= 0) {
    set_mode(&prev_mode, input_mode);
    get_info(prev_mode, &input_distance, &input_oil);
    show_info(prev_mode, input_distance, input_oil);
    printf("������ ���� 0, �̱��� ���� 1�� �Է��Ͻÿ�");
    printf("(�������� -1): ");
    scanf("%d", &input_mode);
  }
  printf("����.\n");

  return 0;
}