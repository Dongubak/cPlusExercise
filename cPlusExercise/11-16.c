#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]) {

  //argv[1]
  char tmp[10];
  if (argc < 2) {
    while (fgets(tmp, 10, stdin)) {
      printf("%s", tmp);
    }
  }
  else {
    if (!strcmp(argv[1], "-p")) {
      while (fgets(tmp, 10, stdin)) {
        printf("%s", tmp);
      }
    }
    else if (!strcmp(argv[1], "-u")) {
      while (fgets(tmp, 10, stdin)) {
        int i;
        for (i = 0; i < strlen(tmp); i++) {
          printf("%c", toupper(tmp[i]));
        }
      }
    }
    else if (!strcmp(argv[1], "-l")) {
      while (fgets(tmp, 10, stdin)) {
        int i;
        for (i = 0; i < strlen(tmp); i++) {
          printf("%c", tolower(tmp[i]));
        }
      }
    }
    else {
      while (fgets(tmp, 10, stdin)) {
        printf("%s", tmp);
      }
    }
  }
  
 
  
  return 0;
}