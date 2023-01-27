#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int main13_2(int argc[], char *argv[]) {

  /*argv[1] : 소스파일 , argv[2] : 타깃파일*/

  if (argc != 3) {
    printf("명령행 전달인자\n");
    printf("argv[1] : 소스파일 , argv[2] : 타깃파일");
    exit(EXIT_FAILURE);
  }


  FILE* in = (void*)0;

  char input_string[10] = { 0 };
  int input_numbers[10] = { 0 };

  if ((in = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  if (fread(input_string, sizeof(char), 10, in) != 10) {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  fseek(in, 10L, SEEK_SET);

  if (fread(input_numbers, sizeof(int), 10, in) != 10) {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  int i;

  for (i = 0; i < 10; i++) {
    printf("[0] : %c : %d\n", input_string[i], input_numbers[i]);
  }




  FILE* out = (void*)0;

  if ((out = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  if (fwrite(input_string, sizeof(char), 10, out) != 10) {
    fprintf(stderr, "cant write to file");
    exit(EXIT_FAILURE);
  }

  fseek(out, 10L, SEEK_SET);
  if (fwrite(input_numbers, sizeof(int), 10, out) != 10) {
    fprintf(stderr, "cant write to file");
    exit(EXIT_FAILURE);
  }

  if (fclose(out) != 0) {
    fprintf(stderr, "file cant close");
    exit(EXIT_FAILURE);
  }



  FILE* in2 = (void*)0;

  char input_string2[10] = { 0 };
  int input_numbers2[10] = { 0 };

  if ((in2 = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  if (fread(input_string2, sizeof(char), 10, in2) != 10) {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  fseek(in2, 10L, SEEK_SET);

  if (fread(input_numbers2, sizeof(int), 10, in2) != 10) {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  if (fclose(in2) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < 10; i++) {
    printf("[0] : %c : %d\n", input_string2[i], input_numbers2[i]);
  }
  return 0;
}