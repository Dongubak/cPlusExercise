#include <stdio.h>
///������ �迭�̸��� �ϳ��� �迭 ũ�⸦ �������ڷ� ���� ����
void merge_arr(const int*, const int*, int*, int);
void display_arr(int*, int);

int main10_10(void) {
  int arr1[4] = { 2, 4, 5, 8 };
  int arr2[4] = { 1, 0, 4, 6 };
  int arr3[4];

  merge_arr(arr1, arr2, arr3, 4);
  display_arr(arr3, 4);

  return 0;
}

void merge_arr(const int*first_source, const int*second_source, int*pt, int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    *(pt + iter) = *(first_source + iter) + *(second_source + iter);
  }
}

void display_arr(int*pt, int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    printf("arr3[%d] : %d\n", iter, *(pt + iter));
  }
}