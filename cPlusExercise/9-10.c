#include <stdio.h>
#pragma warning(disable : 4996)
void to_base_n(unsigned long n, int nt);

int main9_10(void) {
  unsigned long number;
  printf("���� �ϳ��� �Է��Ͻÿ�(�������� q):\n");
  while (scanf("%ul", &number) == 1) {
    int nt;
    printf("������ �Է��Ͻÿ�(�������� q):\n");
    while (scanf("%d", &nt) != 1) {
      printf("�ùٸ� �Է��� �ƴմϴ�");
    }
    printf("%d���� ǥ��: ", nt);
    to_base_n(number, nt);
    putchar('\n');
    printf("���� �ϳ��� �Է��Ͻÿ�(�������� q):\n");
  }
  printf("����!");
  return 0;
}

void to_base_n(unsigned long n, int nt) {
  int r;

  r = n % nt;
  if (n >= nt) {
    to_base_n(n / nt, nt);
  }
  printf("%d", r);
  return;
}