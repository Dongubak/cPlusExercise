#include <stdio.h>
#pragma warning(disable: 4996)
///���� �� > ������ ��
///max���� ��������, �������� min�� max�� �������
///���� �� < ������ ��
///min���� ��������, �������� min�� max�� �������
int main8_5(void) {
  char input_char;
  int tmp_max = 100;
  int tmp_guess = 50;
  int tmp_min = 1;
  printf("1-100���� �����϶�\n");
  printf("������ ���� �ý������������� ������ d, ũ�� u, ������ c�Է��϶�\n");
  printf("������ ���� %d�ΰ�?\n", tmp_guess);
  while ((input_char = getchar()) != '\n') {
    if (input_char == 'd') {
      tmp_max = tmp_guess;
      tmp_guess = (tmp_min + tmp_max) / 2;
      printf("������ ���� %d�ΰ�?\n", tmp_guess);
    }
    else if(input_char == 'u') {
      tmp_min = tmp_guess;
      tmp_guess = (tmp_min + tmp_max) / 2;
      printf("������ ���� %d�ΰ�?\n", tmp_guess);
    }
    else {
      break;
    }

    while (getchar() != '\n') {
      continue;
    }
  }
  printf("����� ������ ���� %d�Դϴ�", tmp_guess);

  return 0;
}