#include <stdio.h>
#include <ctype.h>
#pragma warning(disable: 4996)

int main8_4(void) {
  int input_char;
  int word_count = 0; ///단어의 개수
  int letter_count = 0; ///글자의 개수
  int tem_letter_count = 0; ///한 단어 사이클동안의 letter의 개수
  while ((input_char = getchar()) != EOF) {
    if (ispunct(input_char)) {
      continue;
    }

    if (input_char == ' ' || input_char == '\n') {
      ++word_count; ///white space라면 word_count(단어개수) 증가
      letter_count += tem_letter_count; ///white space라면 전체 letter의 개수 acc
      tem_letter_count = 0; ///한 사이클 letter개수 초기화
      continue;
    }
    tem_letter_count++;
  }
  word_count++;///마지막 단어 추가
  letter_count += tem_letter_count; ///tem_letter값 마지막으로 acc
  
  printf("단어의 개수 : %d\n", word_count);
  printf("글자의 개수 : %d\n", letter_count);
  printf("단어당 사용된 평균 글자수 : %.2f\n", (float)letter_count / word_count);

  return 0;
}