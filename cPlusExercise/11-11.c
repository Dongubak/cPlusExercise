#include <stdio.h>
#include <string.h>
#include "custom.h"

#define ROW 10
#define COL 50
#pragma warning(disable: 4996)

void s_sorted_puts(int (*fp)(char *, char *), char**string);
int origin(char *first_string, char *second_string) {
  return -1;
}
int string_len(char* first_string, char* second_string) {
  if (strlen(first_string) > strlen(second_string)) {
    return 1;
  }
  else {
    return -1;
  }
}
int first_words_len(char* first_string, char* second_string) {

  int first_string_len = strchr(first_string, ' ') == NULL ?
    strlen(first_string) : first_string - strchr(first_string, ' ');
  int second_string_len = strchr(second_string, ' ') == NULL?
    strlen(second_string) : second_string - strchr(second_string, ' ');

  if (first_string_len > second_string_len) {
    return 1;
  }
  else {
    return -1;
  }
}

int main(void) {

  printf("문자열 %d개를 입력하시오(quit 입력시 입력 종료) : \n", ROW);
  char** strings = s_gets_gets(ROW, COL, "quit");
  char input_char;
  printf("a) 원본순서 , b) ASCII순서, c) 문자열 길이순서 , d) 첫 단어 길이순서\n");

  while (scanf("%c", &input_char) == 1 && input_char != 'q') {
    clear_buf();
    switch (input_char) {
      case 'a':
        s_sorted_puts(origin, strings);
        break;
      case 'b':
        s_sorted_puts(strcmp, strings);
        break;
      case 'c':
        s_sorted_puts(string_len, strings);
        break;
      case 'd':
        s_sorted_puts(first_words_len, strings);
        break;
      default:
        NULL;
    }

    printf("a) 원본순서 , b) ASCII순서, c) 문자열 길이순서 , d) 첫 단어 길이순서\n");
  }

  free(strings);
  
  return 0;
}

void s_sorted_puts(int (*fp)(char*, char*), char** string) {

  char** target = (char**)malloc(sizeof(char*) * ROW);
  for (int i = 0; i < ROW; i++) {
    target[i] = string[i];
  }

  int i = 0, j = 0;
  for (i = 0; i < ROW - 1; i++) {
    for (j = i + 1; j < ROW; j++) {
      if (fp(target[i], target[j]) > 0) {
        char* tmp = target[i];
        target[i] = target[j];
        target[j] = tmp;
      }
    }
  }

  for (int i = 0; i < ROW; i++) {
    printf("%s\n", target[i]);
  }

  free(target);
}

//문자열 10개를 입력하시오(quit 입력시 입력 종료) :
//  Picture perfect, you don't need no filter
//  Gorgeous, make 'em drop dead, you're a killer
//  Shower you with all my attention
//  Stay in the kitchen cookin' up, got your own bread
//  Make sure that you don't need no mentions
//  Shout out to your mom and dad for makin' you
//  That kind of smile that makes the news
//  You got a mean touch, I can't refuse (No, I can't refuse it)
//  Shower you with all my attention
//  Yeah, these are my only intentions
//  a) 원본순서, b) ASCII순서, c) 문자열 길이순서, d) 첫 단어 길이순서
//  a
//  Picture perfect, you don't need no filter
//  Gorgeous, make 'em drop dead, you're a killer
//  Shower you with all my attention
//  Stay in the kitchen cookin' up, got your own brea
//  Make sure that you don't need no mentions
//  Shout out to your mom and dad for makin' you
//  That kind of smile that makes the news
//  You got a mean touch, I can't refuse (No, I can't
//  Shower you with all my attention
//  Yeah, these are my only intentions
//  a) 원본순서, b) ASCII순서, c) 문자열 길이순서, d) 첫 단어 길이순서
//  b
//  Gorgeous, make 'em drop dead, you're a killer
//  Make sure that you don't need no mentions
//  Picture perfect, you don't need no filter
//  Shout out to your mom and dad for makin' you
//  Shower you with all my attention
//  Shower you with all my attention
//  Stay in the kitchen cookin' up, got your own brea
//  That kind of smile that makes the news
//  Yeah, these are my only intentions
//  You got a mean touch, I can't refuse (No, I can't
//  a) 원본순서, b) ASCII순서, c) 문자열 길이순서, d) 첫 단어 길이순서
//  c
//  Shower you with all my attention
//  Shower you with all my attention
//  Yeah, these are my only intentions
//  That kind of smile that makes the news
//  Make sure that you don't need no mentions
//  Picture perfect, you don't need no filter
//  Shout out to your mom and dad for makin' you
//  Gorgeous, make 'em drop dead, you're a killer
//  Stay in the kitchen cookin' up, got your own brea
//  You got a mean touch, I can't refuse (No, I can't
//  a) 원본순서, b) ASCII순서, c) 문자열 길이순서, d) 첫 단어 길이순서
//  d
//  Gorgeous, make 'em drop dead, you're a killer
//  Picture perfect, you don't need no filter
//  Shower you with all my attention
//  Shower you with all my attention
//  Shout out to your mom and dad for makin' you
//  Yeah, these are my only intentions
//  That kind of smile that makes the news
//  Make sure that you don't need no mentions
//  Stay in the kitchen cookin' up, got your own brea
//  You got a mean touch, I can't refuse (No, I can't
//  a) 원본순서, b) ASCII순서, c) 문자열 길이순서, d) 첫 단어 길이순서
//  q
//
//  C : \Users\admin\Documents\Cprogramming\cPlusExercise\x64\Debug\cPlusExercise.exe(process 10072) exited with code 0.
//  Press any key to close this window . . .