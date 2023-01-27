#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#define LEN 40

char* input_filename(void);

int main13_8(int argc, char *argv[]) {
  char find_ = 0;
  char** filenames;
  int count = 0;

  if (argc < 3) { ///���� �ڿ� �����̸� ���� x���
    char* tmp_filename = (void*)0;
    int file_name_count = 0, j = 0;
    filenames = (char**)malloc(sizeof(char*) * 10);

    printf("����࿡ �������ڰ� �����ϹǷ� ǥ���Է»��\n");
    printf("ã������ �����Է� : ");
    scanf("%c", &find_);

    while (getchar() != '\n') {
      continue;
    }
    while ((tmp_filename = input_filename()) != NULL) {
      filenames[file_name_count] = tmp_filename;
      file_name_count++;
    }
    count = file_name_count;
  }
  else {
    int i = 0;
    find_ = argv[1][0];///ã������ ���� �Է�
    filenames = (char**)malloc(sizeof(char*) * (argc - 1));
    for (i = 2; i < argc; i++) {
      filenames[i - 2] = argv[i];
    }
    count = argc - 2;
  }
  if (count == 0) {
    printf("�����̸��� �Է����� �ʾҽ��ϴ�.");
    exit(EXIT_FAILURE);
  }
  int i = 0;
  FILE* in = (void*)0;
  char input_char = 0;
  int find_count = 0;
  for (i = 0; i < count; i++) {
    if ((in = fopen(filenames[i], "r")) == NULL) {
      printf("%s file error �߻�!\n", filenames[i]);
      continue;
    }

    while ((input_char = fgetc(in)) != EOF) {
      if (input_char == find_) {
        find_count++;
      }
    }
    printf("filename : %s, find_ : %c, find_count : %d\n", filenames[i], find_, find_count);
    find_count = 0;
  }
  
  free(filenames);
  return 0;
}

char* input_filename(void)
{
  char filename[20] = { 0 };
  printf("�����̸��� �Է��Ͻÿ�");
  printf("(����� #): ");
  scanf("%s", filename);
  if (filename[0] == '#') {
    return (void *)0;
  }
  else {
    char* filename_pt = (char*)malloc(sizeof(char) * strlen(filename) + 1);
    strcpy(filename_pt, filename);
    return filename_pt;
  }
}
