#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable :4996)

///(buffer, maxCount) -> char* : maxCount�̻��� ���ڴ� ����Ѵ�.
char* s_gets(char* st, int n);
///(buffer) -> void : ���ڿ� ���(����x)
void put1(const char* string);
///(buffer, len) -> void : buffer + len�� �ι��� �־� ���̸� ����
void fit(char* string, unsigned int size);
//(row, col, quit_string) -> �Է¹��� ���ڿ������� �迭 : row���� ���ڿ��� �Է¹޾� �����迭 ����
//�Է������ �����Է�, col�����ʰ����ڴ� ���
char** s_gets_gets(int row, int col, const char* quit_string);
///(void) -> void : ���� ����
void clear_buf(void);