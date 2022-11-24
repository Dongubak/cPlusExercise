#include <stdio.h>
#include <ctype.h>
#pragma warning(disable : 4996)

int evaluateChar(char inputChar);

int main9_7(void) {
  char inputChar;

  while ((inputChar = getchar()) != EOF) {
    printf("%d", evaluateChar(inputChar));
  }

  return 0;
}

int evaluateChar(char inputChar) {
  int returnValue;

  if (inputChar > 64 && inputChar < 91) {
    returnValue = inputChar - 64;
  }
  else if (inputChar > 96 && inputChar < 123){
    returnValue = inputChar - 96;
  }
  else {
    returnValue = -1;
  }

  return returnValue;
}