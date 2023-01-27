#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable: 4996)

char* custom_gets(void);
void clear(void) {
  while (getchar() != '\n')
    continue;
}

int main12_9(void) {

  int input_words_count;

  printf("단어의 개수를 입력하시오: ");
  scanf("%d", &input_words_count);
  clear();

  char** string_pointer = (char**)malloc(input_words_count * sizeof(char*));
  printf("이제 %d개의 단어를 입력하시오: \n", input_words_count);
  int i = 0;
  while (i < input_words_count) {
    string_pointer[i] = custom_gets();
    i++;
  }


  printf("입력한 단어: \n");
  for (i = 0; i < input_words_count; i++) {
    printf("%s\n", string_pointer[i]);
  }

  for (i = 0; i < input_words_count; i++) {
    free(string_pointer[i]);
  }

  free(string_pointer);

  return 0;
}

char* custom_gets(void)
{
  char tmp_input_string[100];
  int letter_count = 0;
  char input_char;

  while (!isspace(input_char = getchar()) && !ispunct(input_char)) {
    tmp_input_string[letter_count++] = input_char;
  }
  tmp_input_string[letter_count] = '\0';
  char* string_pointer = (char*)malloc(sizeof(char) * (letter_count + 1));
  int i;
  strcpy(string_pointer, tmp_input_string);

  return string_pointer;
}
