#include <stdio.h>
#pragma warning(disable: 4996)
#define CSIZE 4

struct name {
  char firstname[15];
  char lastname[15];
};

struct student {
  struct name name;
  float grade[3];
  float avg;///grade의 평균을 저장함.
};

void get_grade(struct student* pt, const int size);
void clear_buf1() {
  while (getchar() != '\n') {
    continue;
  }
}

void get_avg1(struct student* pt, const int size);
void get_info1(struct student* pt, const int size);
void get_total_avg(struct student* pt, const int size);
int main14_5(void) {

  struct student excellent[CSIZE] = {
    {.name.firstname = "Dribble", .name.lastname = "Flossie"},
    {.name.firstname = "Joanna", .name.lastname = "Kaccy"},
    {.name.firstname = "Ashely", .name.lastname = "J"},
    {.name.firstname = "Ruby", .name.lastname = "Mie"},
  };
 
  get_grade(&excellent, CSIZE);
  get_avg1(&excellent, CSIZE);
  get_info1(&excellent, CSIZE);
  get_total_avg(&excellent, CSIZE);

  return 0;
}

void get_grade(struct student* pt, const int size) {
  printf("for inserting score\n");
  for (int outer_iter = 0; outer_iter < size; outer_iter++) {
    int inner_iter = 0;
    printf("-------------------\n");
    printf("name : %12s\n", pt[outer_iter].name.firstname);
    while (inner_iter < 3) {
      printf("%d) Enter the score : ", inner_iter + 1);
      if (scanf("%f", &(pt[outer_iter].grade[inner_iter])) != 1) {
        printf("invalid input!\n");
        clear_buf1();
        continue;
      }
      inner_iter++;
    }
  }
}

void get_avg1(struct student* pt, const int size)
{
  for (int outer_iter = 0; outer_iter < size; outer_iter++) {
    float tmp_sum = 0;
    for (int inner_iter = 0; inner_iter < 3; inner_iter++) {
      tmp_sum += pt[outer_iter].grade[inner_iter];
    }
    pt[outer_iter].avg = tmp_sum / 3;
  }
}

void get_info1(struct student* pt, const int size) {
  printf("============  student info  ============\n");
  printf("----------------------------------------\n");
  for (int outer_iter = 0; outer_iter < size; outer_iter++) {
    printf("first name : %8s, lastname %8s\n", pt[outer_iter].name.firstname, pt[outer_iter].name.lastname);
    printf("\ngrade : ");
    for (int inner_iter = 0; inner_iter < 3; inner_iter++) {
      printf("%.2f ", pt[outer_iter].grade[inner_iter]);
    }
    printf("\n"
                  "                              avg : %.2f\n", pt[outer_iter].avg);
    printf("----------------------------------------\n");
  }
}

void get_total_avg(struct student* pt, const int size) {
  printf("---------- total avg ----------");
  float total = 0;
  for (int outer_iter = 0; outer_iter < size; outer_iter++) {
    float sub_total = 0;
    for (int inner_iter = 0; inner_iter < 3; inner_iter++) {
      sub_total += pt[outer_iter].grade[inner_iter];
    }
    total += sub_total;
  }
  printf("                  total avg : %.2f", total / (size * 3));
}