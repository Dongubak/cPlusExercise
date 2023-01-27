#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

void open_file(char* file_name);

int main13_4(int argc, char *argv[]) {

  if (argc < 2) {
    printf("명령행 전달인자로 파일명을 입력하여 순차적으로 여는 프로그램입니다");
    exit(EXIT_FAILURE);
  }

  int i = 0;

  for (i = 0; i < argc - 1; i++) {
    open_file(argv[i + 1]);
  }

  return 0;
}

void open_file(char* file_name)
{
  FILE* in = (void*)0;
  char input_char = 0;
  if ((in = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }
  printf("file name : %s\n", file_name);
  printf("------------------------------------------------------------------------\n");
  while ((input_char = fgetc(in)) != EOF) {
    printf("%c", input_char);
  }
  printf("\n------------------------------------------------------------------------\n");
  printf("\n");

  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

}