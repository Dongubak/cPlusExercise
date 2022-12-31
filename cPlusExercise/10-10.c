#include <stdio.h>
///������ �迭�̸��� �ϳ��� �迭 ũ�⸦ �������ڷ� ���� ����
void merge_arr(int*, int*, int*, int);
void display_arr(int*, int);

int main10_10(void) {
  int arr1[4] = { 2, 4, 5, 8 };
  int arr2[4] = { 1, 0, 4, 6 };
  int arr3[4];

  merge_arr(arr1, arr2, arr3, 4);
  display_arr(arr3, 4);

  return 0;
}

void merge_arr(int*pt1, int*pt2, int*pt3, int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    *(pt3 + iter) = *(pt1 + iter) + *(pt2 + iter);
  }
}

void display_arr(int*pt, int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    printf("arr3[%d] : %d\n", iter, *(pt + iter));
  }
}