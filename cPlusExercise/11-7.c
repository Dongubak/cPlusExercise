#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

char* my_strncpy(char* destination, const char* source, int count);

int main(void) {

  char destination[10];
  const char *source = "solitary";

  my_strncpy(destination, source, 12);

  printf("%s", destination);

  return 0;
}

char* my_strncpy(char* destination, const char* source, int count) {

  size_t source_len = strlen(source) + 1;
  int i = 0;

  while ((source_len > count) ? i < count : i < source_len) {
    destination[i] = source[i];
    i++;
  }

  destination[i] = '\0';
  return destination;
}