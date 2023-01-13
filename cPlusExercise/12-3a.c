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

  char* error_msg[2] = { "유럽식", "미국식" };

  if ((input_mode == 0) or (input_mode == 1))
    *prev_mode = input_mode;

  else
    printf("모드 지정이 잘못되었습니다. 모드 1(%s)을 사용합니다.\n", error_msg[*prev_mode]);
}

void get_info(int prev_mode, int *input_distance, float *input_oil) {
  char* oil_msg[2] = { "리터", "갤런" };
  char* distance_msg[2] = { "킬로미터", "마일" };

  /*extern int input_distance;
  extern float input_oil;
  extern int prev_mode;*/

  printf("주행한 거리를 %s 단위로 입력하시오 : ", distance_msg[prev_mode]);
  while (!scanf("%d", input_distance)) {
    while (getchar() != '\n')
      continue;
    printf("다시 입력해주세요.\n");
  }

  printf("소비한 휘발유의 양을 %s 단위로 입력하시오: ", oil_msg[prev_mode]);
  while (!scanf("%f", input_oil)) {
    while (getchar() != '\n')
      continue;
    printf("다시 입력해주세요.\n");
  }
}

void show_info(int prev_mode, int input_distance, float input_oil)
{

  switch (prev_mode) {
  case 0:
    printf("유럽식: 100킬로미터당 %.2f 리터입니다.\n", input_oil / (float)input_distance * 100.0);
    break;
  case 1:
    printf("미국식: 갤런당 %.1f 마일입니다.\n", ceil(10 * (float)input_distance / input_oil) / 10);
    break;
  default:
    NULL;
  }
}
