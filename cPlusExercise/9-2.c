#include <stdio.h>
#pragma warning(disable: 4996)

//�μ��� ���� ���ڸ�
//�ι�° �μ����� ������ 
//����° �μ����� ������ 
//����ϴ� �Լ�
void chline(char input_char, int first_column, int second_column);

int main9_2(void) {

  char input_char;

  printf("���ڸ� �Է��Ͻÿ�\n");
  scanf("%c", &input_char);
  chline(input_char, 5, 10);

  return 0;
}

void chline(char input_char, int first_column, int second_column) {
  int iter;
  for (iter = 1; iter < first_column; iter++) {
    printf(" ");
  }
  for (iter = first_column; iter <= second_column; iter++) {
    printf("%c", input_char);
  }
}