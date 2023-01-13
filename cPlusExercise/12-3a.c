#include <stdio.h>
#include <iso646.h>
#include <math.h>
#pragma warning(disable: 4996)

//static int prev_mode = 0;
//static int input_distance = 0;
//static float input_oil = 0.0;
void set_mode(int*, int);
void get_info(int, int*, float*);
//prev_mode, input_distance, input_oil
void show_info(int, int, float);

void set_mode(int *prev_mode, int input_mode) {

  char* error_msg[2] = { "������", "�̱���" };

  if ((input_mode == 0) or (input_mode == 1))
    *prev_mode = input_mode;

  else
    printf("��� ������ �߸��Ǿ����ϴ�. ��� 1(%s)�� ����մϴ�.\n", error_msg[*prev_mode]);
}

void get_info(int prev_mode, int *input_distance, float *input_oil) {
  char* oil_msg[2] = { "����", "����" };
  char* distance_msg[2] = { "ų�ι���", "����" };

  /*extern int input_distance;
  extern float input_oil;
  extern int prev_mode;*/

  printf("������ �Ÿ��� %s ������ �Է��Ͻÿ� : ", distance_msg[prev_mode]);
  while (!scanf("%d", input_distance)) {
    while (getchar() != '\n')
      continue;
    printf("�ٽ� �Է����ּ���.\n");
  }

  printf("�Һ��� �ֹ����� ���� %s ������ �Է��Ͻÿ�: ", oil_msg[prev_mode]);
  while (!scanf("%f", input_oil)) {
    while (getchar() != '\n')
      continue;
    printf("�ٽ� �Է����ּ���.\n");
  }
}

void show_info(int prev_mode, int input_distance, float input_oil)
{

  switch (prev_mode) {
  case 0:
    printf("������: 100ų�ι��ʹ� %.2f �����Դϴ�.\n", input_oil / (float)input_distance * 100.0);
    break;
  case 1:
    printf("�̱���: ������ %.1f �����Դϴ�.\n", ceil(10 * (float)input_distance / input_oil) / 10);
    break;
  default:
    NULL;
  }
}
