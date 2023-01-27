#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)

int main13_10(void) {
  char input_filename[15];
  char buf[100];
  long read_position = 0;
  printf("�����̸��� �Է��Ͻÿ� : ");
  scanf("%s", input_filename);

  printf("���� ���� ��ġ�� ����Ʈ ������ �Է��Ͻÿ�");
  printf("(�� ��ġ���� ���� �������� ���� ���� ���) : ");
  if (scanf("%ld", &read_position) != 1) {
    fprintf(stderr, "��ġ�� ���� �Է��Ͻÿ�");
    exit(EXIT_FAILURE);
  }

  FILE* in = (void*)0;

  if ((in = fopen(input_filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  fseek(in, read_position, SEEK_SET);
  if (fscanf(in, "%[^\n]", buf) == 1) {
    printf("%s", buf);
  }
  else {
    fprintf(stderr, "cant read file");
    exit(EXIT_FAILURE);
  }

  return 0;
}