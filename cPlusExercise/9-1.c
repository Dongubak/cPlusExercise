#include <stdio.h>
#pragma warning(disable: 4996)

//�ΰ��� ������ �μ��� �ް�
//�ΰ��� ������ ���� ������ ��ȯ�ϴ� �Լ�
//���ٸ� �� ���� ��ȯ�Ѵ�.
double min(double x, double y);

int main9_1(void) {
  double first_value = 2.1;
  double second_value = 6.3;

  printf("min value : %lf", min(first_value, second_value));

  return 0;
}

double min(double x, double y) {
  double min_value;
  if (x > y) {
    min_value = y;
  }
  else if(y > x){
    min_value = x;
  }
}