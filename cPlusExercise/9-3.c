#include <stdio.h>
#pragma warning(disable: 4996)

//ù��° �μ��� ���ڸ� �ް�
//�ι�° �μ��� ������ �ް�
//����° �μ��� �ప�� �ް�
//���� �࿡ �����Ǵ� ���� ���ڸ� ����ϴ� �Լ�
void solution(char input_char, int column, int row);

int main9_3(void) {
  solution('a', 10, 2);

  return 0;
}

void solution(char input_char, int column, int row) {
  int iter_1, iter_2;
  for (iter_1 = 1; iter_1 < row; iter_1++) {
    for (iter_2 = 1; iter_2 <= (column + 3); iter_2++) {
      printf(" - ");
    }
    printf("\n");
  }

  for (iter_1 = row; iter_1 <= (row + 3); iter_1++) {
    for (iter_2 = 1; iter_2 <= (column + 3); iter_2++) {
      if (iter_1 == row && iter_2 == column) {
        printf(" %c ", input_char);
      }
      else {
        printf(" - ");
      }
    }
    printf("\n");
  }
}