#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable: 4996)
/*
  ���� �̷���� �� ����Ʈ�� �д´�.
  �� ������ �����Ѵ�.
  ����� ���Ѵ�.
  ���� �׷����� ǥ���Ѵ�.

  readlist(list, SIZE);
  sort(list, SIZE);
  average(list, SIZE);
  bargraph(list, SIZE);

  return 0;
*/
///header : ��ó���� ������ ���, �Լ�������Ÿ��
///body :~~~
///parameter�� ��ȣ���Լ�(�Լ��� ������Ÿ��, ����)�� ����
///argument�� ȣ���Լ��� ���� ���ĸŰ������� ���ԵǴ� Ư���� ��
///������Ÿ�Կ��� ������ �����̸��� ���ǹ����� ������ �����̸��� ���� �ʿ�� ����
///ȣ���Լ�(main)�� ȣ�⹮���� arguments���� stack�� �����Ѵ�
///��ȣ���Լ� imax�� �ΰ��� �������� �дµ� ù��°�� ���ÿ� ���� ��
/// �ι�°�� �쿬�� �ι�° ���ÿ� �־��� ���̴�.
///               ANSI����
///parameter�� ���� arguments�� ���� �ٸ����
///parameter�� ������ arguments�� ����������ȯ ��.
/// 
#define NAME "GIGATHINK, INK."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);
///starbar�� signature�� ���ϰ�x �������� x�� �Լ��̴�.
///�����ݷ��� ������ ������Ÿ���̳� ȣ���� �ƴ� ���Ƿ� �ν��Ѵ�.
///void�������� return;��� ����
///parameter�� ���� arguments�� ���� �ٸ����
///parameter�� ������ arguments�� ����������ȯ ��.
///
int factorial(int n);
void show_info(void) {
  printf("���丮���� ����ϴ� ���α׷��Դϴ�\n");
  printf("0-12������ �� ���� �Է��Ͻÿ�(����� q): ");
}

bool is_valid(int input_number) {
  bool is_valid = true;
  if (input_number > 12 || input_number < 0) {
    printf("0-12������ ���� �Է��Ͻÿ�\n");
    is_valid = false;
  }
  return is_valid;
}

int convert_binary(int input_number) {
  int mod_binary = input_number % 2;
  int div_binary = input_number / 2;
  if (div_binary >= 2) {
    convert_binary(div_binary);
    printf("%d", mod_binary);
  }
  else {
    printf("%d", mod_binary);
  }
}

bool is_valid_1(int input_number) {
  bool is_valid = true;
  if (input_number < 0) {
    is_valid = false;
  }
  return is_valid;
}

int main_play_1(void) {
 
  int input_number;
  while (scanf("%d", &input_number) == 1) {
    if (!is_valid) continue;
    convert_binary(input_number);
  }

  /*show_info();
  while (scanf("%d", &input_number) == 1) {
    if (!is_valid(input_number)) 
      continue;
    printf("%d! = %d\n", input_number, factorial(input_number));
    show_info();
  }*/
  printf("����!");
  return 0;
}

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  else if (n == 0){
    return 1;
  }
  else {
    return factorial(n - 1) * n;
  }
}

void starbar(void) {
  int count;
  for (count = 1; count <= WIDTH; count++) {
    putchar('*');
  }
  putchar('\n');
}