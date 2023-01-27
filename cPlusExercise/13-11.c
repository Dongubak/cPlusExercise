#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int main13_11(int argc, char *argv[]) {

  /*argv[1] : string,
    argv[2] : filename*/

  if (argc != 3) {
    printf("명령행 전달인자 사용");
    exit(EXIT_FAILURE);
  }

  char buf[256] = { 0 };
  FILE* in = (void*)0;

  if ((in = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "file cant open");
    exit(EXIT_FAILURE);
  }

  while (fgets(buf, 256, in)) {
    if (strstr(buf, argv[1])) {
      printf("%s", buf);
    }
  }
  
  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  return 0;
}