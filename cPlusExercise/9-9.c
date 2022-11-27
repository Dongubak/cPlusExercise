#include <stdio.h>
#pragma warning(disable : 4996)

double power_2(double n, int p);
double pow(double n, int p);

int main9_9(void) {
  double x, xpow;
  int exp;

  printf("� ����, ���ϴ� ���� �ŵ���������");
  printf(" �Է��Ͻÿ�.\n�������� q��");
  printf(" �Է��Ͻÿ�\n");
  while (scanf("%lf%d", &x, &exp) == 2) {
    xpow = power_2(x, exp);
    if (xpow == EOF) {
      printf("%.3g�� %d���� %d�Դϴ�.\n", x, exp, 1);
      printf("0�� 0���� ���ǵ��� �ʾҰ� 1�� ���� ������Դϴ�.\n");
      printf("�� ���� �Է��Ͻÿ�. �������� q�� �Է��Ͻÿ�.\n");
      continue;
    }
    else {
      printf("%.3g�� %d���� %.5g�Դϴ�.\n", x, exp, xpow);
      printf("�� ���� �Է��Ͻÿ�. �������� q�� �Է��Ͻÿ�.\n");
    }
  }
  printf("�ŵ����� ���ϱⰡ ��� �־�����? --�ȳ�!\n");

  return 0;
}

double power_2(double n, int p) {
  double returnValue;
  int absP = p < 0 ? -p : p;

  if (n == 0 && p == 0) {
    return EOF;
  }
  else if (p == 0) {
    return 1;
  }
  else if (n == 0) {
    return 0;
  }
  else {
    if (p > 0) {
      returnValue = pow(n, p);
    }
    else {
      returnValue = pow(1 / n, absP);
    }
  }
  return returnValue;
}

double pow(double n, int p) {
  if (p == 1) {
    return n;
  }
  else {
    return n * pow(n, p - 1);
  }
}