#include <stdio.h>
#pragma warning(disable: 4996)

//first_input�� second_input�� ���Ͽ�
//�� �� ���� ���� ��ȯ�ϴ� �Լ�
double min(double first_input, double second_input);

int main9_1(void) {
  double first_value = 2.1;
  double second_value = 6.3;

  printf("min value : %lf", min(first_value, second_value));

  return 0;
}

double min(double first_input, double second_input) {
  double min_value;
  if (first_input > second_input) {///first_input �� second_input���� ū ��� second_input ��ȯ
    min_value = second_input;
  }
  else if(second_input > first_input){///second_input �� first_input���� ū ��� first_input ��ȯ
    min_value = first_input;
  }
  else {
    min_value = first_input;
    printf("�Է��� �� ���� �����ϴ�\n");
  }
  return min_value;
}