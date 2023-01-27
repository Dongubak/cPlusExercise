#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable: 4996)

void input_names(char* source_name, char* target_name);

int main13_3(void) {

  char  source_name[15] = { 0 }, target_name[15] = { 0 };
  input_names(source_name, target_name);
  
  FILE* in = (void*)0, *out = (void*)0;
  char input_char;

  if ((in = fopen(source_name, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  if ((out = fopen(target_name, "w+")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  while ((input_char = fgetc(in)) != EOF) {
    printf("%c", input_char);
  }

  fseek(in, 0L, SEEK_SET);

  while ((input_char = fgetc(in)) != EOF) {
    if (isalpha(input_char)) {
      fputc(toupper(input_char), out);
    }
    else {
      fputc(input_char, out);
    }
  }

  fseek(out, 0L, SEEK_SET);
  while ((input_char = fgetc(out)) != EOF) {
    printf("%c", input_char);
  }

  if (fclose(in) != 0 || fclose(out) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  return 0;
}

void input_names(char* source_name, char* target_name)
{
  printf("enter the source file's name: ");
  scanf("%s", source_name);

  printf("enter the target file's name: ");
  scanf("%s", target_name);

  printf("source name : %s, target name: %s\n", source_name, target_name);
}
