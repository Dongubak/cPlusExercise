#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)

int main13_10(void) {
  char input_filename[15];
  char buf[100];
  long read_position = 0;
  printf("파일이름을 입력하시오 : ");
  scanf("%s", input_filename);

  printf("파일 내의 위치를 바이트 단위로 입력하시오");
  printf("(그 위치부터 개행 전까지의 파일 내용 출력) : ");
  if (scanf("%ld", &read_position) != 1) {
    fprintf(stderr, "수치형 값을 입력하시오");
    exit(EXIT_FAILURE);
  }

  FILE* in = (void*)0;

  if ((in = fopen(input_filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  fseek(in, read_position, SEEK_SET);
  if (fscanf(in, "%[^\n]", buf) == 1) {
    printf("%s", buf);
  }
  else {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  return 0;
}