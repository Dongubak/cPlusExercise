#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

struct civil {
  char number[11];
  struct { char firstname[15]; char middlename[15]; char lastname[15]; };
};

typedef struct civil CV;
  

int main14_4(void) {

  CV people[5] = {
    {"302039823", {"Dribble", "Flossie", "M"}},
    {"302039824", {"Joanna", "Kaccy", "Smith"}},
    {"302039825", {"Ashely", "J", "Miller"}},
    {"302039826", {"Ruby", "Mie", "Yang"}},
    {"302039827", {"Visha", "\0", "Long"}}
  };

  int i;
  for (i = 0; i < 5; i++) {
    printf("%8s, %8s %8s -- %s\n", (people + i)->firstname, (people + i)->lastname
      , (people + i)->middlename[0] == '\0' ? "\0" : strcat((people + i)->middlename, "."), people->number);
  }

  return 0;
}