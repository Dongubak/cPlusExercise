#include <stdio.h>
#pragma warning(disable: 4996)

//ù��° �μ��� ���ڸ� �ް�
//�ι�° �μ��� ������ �ް�
//����° �μ��� �ప�� �ް�
//���� �࿡ �����Ǵ� ���� ���ڸ� ����ϴ� �Լ�
void input_char_in_matrix(char input_char, int column, int row);

int main9_3(void) {
  input_char_in_matrix('a', 8, 2);

  return 0;
}

void input_char_in_matrix(char input_char, int column, int row) {
  int outer_iter, inner_iter;
  
  for (outer_iter = 0; outer_iter < 10; outer_iter++) {
    for (inner_iter = 0; inner_iter < 10; inner_iter++) {
      if (outer_iter == row && inner_iter == column) {
        printf("  %c  ", input_char);
      }
      else {
        printf("  -  ");
      }
    }
    printf("\n\n");
  }
}