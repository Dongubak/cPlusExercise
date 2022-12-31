#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
#define LIM 10

char* mystrncpy(char* target, char* copied, int n);

int main11_7(void) {

  char arr[LIM];
  char *test[3] = { "BBB", "CCCCCCCCCC", "DDDDDDDDDDDD" };
  int i;
  
  for (i = 0; i < 3; i++) {
    strcpy(arr, "AAA"); ///initialize target
    mystrncpy(arr, test[i], strlen(test[i]));
    printf("mystrncopy 함수 적용 : %s\n", arr);
  }

  return 0;
}

char* mystrncpy(char* target, char* copied, int n) {
  int i;
  /*target크기인 경우(n < target or (n >= target && target > copied))
    copied의 크기인 경우(n >= target || copied >= target)*/

  if (n < LIM || (n >= LIM && LIM > strlen(copied))) {
    for (i = 0; i < LIM; i++) {
      if (n < LIM && i > n - 1) {
        target[i] = '\0';
      }
      else if (i > strlen(copied) - 1){
        target[i] = '\0';
      }
      else {
        target[i] = copied[i];
      }
    }

  }
  else {
    for (i = 0; i < strlen(copied); i++) {
      target[i] = copied[i];
    }
    target[strlen(copied)] = '\0';
  }

  return target;
}