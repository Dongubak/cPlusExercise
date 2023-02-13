#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///(buffer, maxCount) -> char* : maxCount�̻��� ���ڴ� ����Ѵ�.
char* s_gets(char* st, int n);
///(buffer) -> void : ���ڿ� ���(����x)
void put1(const char* string);
///(buffer, len) -> void : buffer + len�� �ι��� �־� ���̸� ����
void fit(char* string, unsigned int size);
//(row, col, quit_string) -> �Է¹��� ���ڿ������� �迭 : row���� ���ڿ��� �Է¹޾� �����迭 ����
//�Է������ �����Է�, col�����ʰ����ڴ� ���
char** s_gets_gets(int row, int col, const* quit_string);
///(void) -> void : ���� ����
void clear_buf(void);

char* s_gets(char* st, int n) {
  char* ret_val;
  int i = 0;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
    else
      while (getchar() != '\n')
        continue;
  }

  return ret_val;
}

void put1(const char* string)
{
  while (*string != '\0') {
    putchar(*string++);
  }
}

void fit(char* string, unsigned int size) {
  if (strlen(string) > size)
    *(string + size) = '\0';
}

//(row, col, quit_string) -> �Է¹��� ���ڿ������� �迭 : row���� ���ڿ��� �Է¹޾� �����迭 ����
//�Է������ �����Է�, col�����ʰ����ڴ� ���
char** s_gets_gets(int row, int col, const* quit_string)
{
  char** input = (char**)malloc(sizeof(char*) * row);
  int i;
  for (i = 0; i < row; i++) {
    input[i] = (char*)malloc(sizeof(char) * col);
  }
  int ct = 0;
  while (ct < row &&
    s_gets(input[ct], col) != NULL && 
    strcmp(input[ct], quit_string) != 0) {
    ct++;
  }

  return input;
}

void clear_buf(void) {
  while (getchar() != '\n') {
    continue;
  }
}