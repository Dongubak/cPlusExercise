/* global.c  -- uses an external variable */
#include <stdio.h>
#pragma warning(disable: 4996)

void critic(int *);

int main12_1(void)
{
  int units;  /* an optional redeclaration */

  printf("How many pounds to a firkin of butter?\n");
  scanf("%d", &units);
  while (units != 56)
    critic(&units);
  printf("You must have looked it up!\n");

  return 0;
}

void critic(int *units)
{
  /* optional redeclaration omitted */
  printf("No luck, my friend. Try again.\n");
  scanf("%d", units);
}