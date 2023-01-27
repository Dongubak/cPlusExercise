#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int* make_array(int element_count, int val);
void show_array(const int dynamic_array_pt[], int element_count);

int main12_8(void) {

  int* dynamic_array_pt;
  int element_count;
  int input_value;
  
  printf("������ ������ �Է��Ͻÿ�: ");

  while (scanf("%d", &element_count) == 1 && element_count > 0) {
    printf("�ʱ�ȭ ���� �Է��Ͻÿ�: ");

    scanf("%d", &input_value);
    dynamic_array_pt = make_array(element_count, input_value);
    if (dynamic_array_pt) {
      show_array(dynamic_array_pt, element_count);
      free(dynamic_array_pt);
    }
    printf("\n������ ������ �Է��Ͻÿ�(�������� < 1): ");
  }
  printf("����.\n");

  return 0;
}

int* make_array(int element_count, int input_value) {
  int* alloc_pointer = (int*)malloc(sizeof(int) * element_count);
  int i;

  for (i = 0; i < element_count; i++) {
    alloc_pointer[i] = input_value;
  }
  return alloc_pointer;
}
void show_array(const int dynamic_array_pt[], int element_count) {
  int i;
  for (i = 0; i < element_count; i++) {
    printf("%4d", dynamic_array_pt[i]);
    if (i % 8 == 7) {
      printf("\n");
    }
  }
}