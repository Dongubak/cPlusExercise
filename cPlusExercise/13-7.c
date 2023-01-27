#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>
#pragma warning(disable: 4996)
#define LEN 40

int main13_7(void) {

  /*char first_input_filename[LEN] = { 0 }, second_input_filename[LEN] = { 0 };
  printf("enter the first filename : ");
  scanf("%s", first_input_filename);

  printf("enter the second filename : ");
  scanf("%s", second_input_filename);*/

  char first_input_filename[LEN] = "file1.txt";
  char second_input_filename[LEN] = "file2.txt";
  bool first_flag = false, second_flag = false;
  FILE* in1 = (void*)0, * in2 = (void*)0;

  if ((in1 = fopen(first_input_filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  if ((in2 = fopen(second_input_filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  while (!(first_flag == true and second_flag == true)) {
    char input_char;
    if (first_flag == false) {
      while ((input_char = fgetc(in1)) != '\n' and input_char != EOF) {
        printf("%c", input_char);
      }
      if (input_char == EOF) {
        first_flag = true;
      }
    }
    printf("                                  ");
    if (second_flag == false) {
      while ((input_char = fgetc(in2)) != '\n' and input_char != EOF) {
        printf("%c", input_char);
      }
      if (input_char == EOF) {
        second_flag = true;
      }
    }
    printf("\n");
  }

  if (fclose(in1) != 0 or fclose(in2) != 0) {
    fprintf(stderr, "cant close file");
  }
  
  return 0;
}