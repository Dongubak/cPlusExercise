#include <stdio.h>
#include <ctype.h>
#include <string.h>

int c_count(char *string, int *count_arr);

int main(void) {

  int buf[128];
  int w_u_l_p[4] = { 0 }; ///words, uppers, lowers, puncts

  while (fgets(buf, 128, stdin) && buf[0] != EOF)
    c_count(buf, w_u_l_p);

  printf("words : %d, uppers : %d, lowers : %d, punct : %d", w_u_l_p[0], w_u_l_p[1], w_u_l_p[2], w_u_l_p[3]);

  return 0;
}

int c_count(char *string, int* count_arr) {

  size_t str_len = strlen(string);

  for (int i = 0; i < str_len; i++) {

    if (isupper(string[i]))
      count_arr[1] += 1;

    else if (islower(string[i]))
      count_arr[2] += 1;

    else if (ispunct(string[i]))
      count_arr[3] += 1;

    else if (isspace(string[i]))
      count_arr[0] += 1;

  }
}