#include <stdio.h>
#include <ctype.h>
#pragma warning(disable: 4996)

int main8_4(void) {
  int input_char;
  int word_count = 0; ///�ܾ��� ����
  int letter_count = 0; ///������ ����
  int tem_letter_count = 0; ///�� �ܾ� ����Ŭ������ letter�� ����
  while ((input_char = getchar()) != EOF) {
    if (ispunct(input_char)) {
      continue;
    }

    if (input_char == ' ' || input_char == '\n') {
      ++word_count; ///white space��� word_count(�ܾ��) ����
      letter_count += tem_letter_count; ///white space��� ��ü letter�� ���� acc
      tem_letter_count = 0; ///�� ����Ŭ letter���� �ʱ�ȭ
      continue;
    }
    tem_letter_count++;
  }
  word_count++;///������ �ܾ� �߰�
  letter_count += tem_letter_count; ///tem_letter�� ���������� acc
  
  printf("�ܾ��� ���� : %d\n", word_count);
  printf("������ ���� : %d\n", letter_count);
  printf("�ܾ�� ���� ��� ���ڼ� : %.2f\n", (float)letter_count / word_count);

  return 0;
}