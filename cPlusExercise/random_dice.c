#include <stdio.h>

static unsigned long int next;

unsigned short random_dice(unsigned short area_count) {
  
  next = next * 1103515245 + 12345;
  return (unsigned short)(next / 65536) % area_count + 1;
}

void change_seed(unsigned int input_seed) {
  next = input_seed;
}