#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <string.h>
#pragma warning(disable: 4996)
#define CSEAT 12

struct seat {
  int seat_number;
  bool is_resereved;
  struct {
    char firstname[15];
    char lastname[15];


  } reserved_info;
};
int* get_reserved_index(struct seat  colouss_airlines[12]);
int get_reserved_seat_count(struct seat colouss_airlines[12]);
bool init_data(struct seat* pt, char* filename);

void clear_buf();

//seat_number : 정수형 => 좌석번호
//is_reserved : bool형 => 좌석예약유무
//reserved_info.firstname : 문자열 => 예약이 되어있다면 예약자의 성
//reserved_info.lastname : 문자열 => 예약이 되어있다면 예약자의 이름

void test_display(struct seat *colouss_airlines) {
  for (int i = 0; i < 12; i++) {
    printf("%d %d %s %s\n", 
      colouss_airlines[i].seat_number, 
      colouss_airlines[i].is_resereved, 
      colouss_airlines[i].reserved_info.firstname, 
      colouss_airlines[i].reserved_info.lastname);
  }
}

void print_menu(void) {
  printf("------------------------------------------------------------------------------------------\n");
  printf("a)비어 있는 좌석 수 표시  b)비어 있는 좌석 목록 표시   c)예약된 좌석을 고객 이름의 알파벳 순으로 표시\n");
  printf("d)좌석 예약             e)예약 취소                 f)프로그램 종료\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("\n");
}

int main(void) {

  struct seat colouss_airlines[12] = { 0 };
  init_data(colouss_airlines, "airline_data.txt");

  //printf("%d %d %s %s",
  //  colouss_airlines[5].seat_number,
  //  colouss_airlines[5].is_resereved,
  //  colouss_airlines[5].reserved_info.firstname,
  //  colouss_airlines[5].reserved_info.lastname);

  char input_alpha = 0;

  while (true) {
    print_menu();
    if (scanf("%c", &input_alpha) != 1) {
      clear_buf();
      printf("Enter the a to f!\n");
    }
    clear_buf();

    if (input_alpha == 'f') {
      FILE* out = (void*)0;
      if ((out = fopen("airline_data.txt", "w")) == NULL) {
        fprintf(stderr, "cant open file");
        exit(EXIT_FAILURE);
      }
      int i = 0;
      while (i < 12 && fprintf(out, "%d %d %s %s\n",
        colouss_airlines[i].seat_number,
        (int)(colouss_airlines[i].is_resereved),
        colouss_airlines[i].reserved_info.firstname,
        colouss_airlines[i].reserved_info.lastname)) {
        i++;
      }

      if (fclose(out) != 0) {
        fprintf(stderr, "file cant close");
        exit(EXIT_FAILURE);
      }

      break;
    }

    if (input_alpha == 'a') {
      printf("비어있는 좌석 수 : %d\n", 12 - get_reserved_seat_count(colouss_airlines));
    }

    if (input_alpha == 'b') {
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);
      printf("비어있는 좌석 목록 : ");

      struct seat* pt = colouss_airlines;

      while ((i < 12) && (j < reserved_count)) {
        if (i == reserved_index[j]) {
          i++;
          j++;
        }
        else {
          printf(" %d ", colouss_airlines[i].seat_number);
          i++;
          continue;
        }
      }

      free(reserved_index);
      printf("\n");
    }

    if (input_alpha == 'c') {
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);

      struct seat* sorted_seats = (struct seat*)malloc(sizeof(struct seat) * reserved_count);

      for (i = 0; i < reserved_count; i++) {
        sorted_seats[i] = colouss_airlines[reserved_index[i]];
      }

      /*for (i = 0; i < reserved_count; i++) {
      printf("%d", sorted_seats[i].seat_number);
      }*/

      for (i = 0; i < reserved_count - 1; i++) {
        for (j = i + 1; j < reserved_count; j++) {
          if (strcmp(sorted_seats[i].reserved_info.firstname, sorted_seats[j].reserved_info.firstname) > 0) {
            struct seat tmp = sorted_seats[j];
            sorted_seats[j] = sorted_seats[i];
            sorted_seats[i] = tmp;
          }
        }
      }

      for (i = 0; i < reserved_count; i++) {
        printf("%d %s %s\n", sorted_seats[i].seat_number, sorted_seats[i].reserved_info.firstname, sorted_seats[i].reserved_info.lastname);
      }

      free(reserved_index);
      printf("\n");
    }

    if (input_alpha == 'd') {
      ///비어있는 좌석 목록을 보여준다.
      ///원하는 좌석의 번호를 입력하게 한다. 이때 입력을 취소할 수 있어야 한다.
      ///정상적인 좌석번호를 입력한 경우 파일을 수정한다.
      ///정상적인 입력이 아닌 경우(올바른 좌석번호를 입력하지 않은 경우) 에러 메세지를 출력한다.
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);
      printf("비어있는 좌석 목록 : ");

      struct seat* pt = colouss_airlines;

      while ((i < 12) && (j < reserved_count)) {
        if (i == reserved_index[j]) {
          i++;
          j++;
        }
        else {
          printf(" %d ", colouss_airlines[i].seat_number);
          i++;
          continue;
        }
      }


      printf("\n");

      int input_seat_number = 0;

      printf("예약하고자 하는 좌석넘버를 입력하시오 (종료시 q) :");

      while (scanf("%d", &input_seat_number) == 1) {
        int i = 0;
        bool is_reserved_seat = false;
        for (i = 0; i < reserved_count; i++) {
          if (input_seat_number == colouss_airlines[reserved_index[i]].seat_number) {
            is_reserved_seat = true;
          }
        }

        if (is_reserved_seat) {
          printf("이미 예약된 좌석입니다.\n");
          printf("다른 좌석을 예약해주세요.\n");
          printf("예약하고자 하는 좌석넘버를 입력하시오 (종료시 q) :");
          continue;
        }
        else {
          break;
        }
      }


      struct seat new_reserver;
      clear_buf();
      printf("예약자의 성을 입력하시오. : ");
      scanf("%s", new_reserver.reserved_info.firstname);

      printf("예약자의 이름을 입력하시오 : ");
      scanf("%s", new_reserver.reserved_info.lastname);

      new_reserver.is_resereved = true;
      new_reserver.seat_number = input_seat_number;

      for (i = 0; i < 12; i++) {
        if (colouss_airlines[i].seat_number == input_seat_number) {
          colouss_airlines[i] = new_reserver;
        }
      }
      printf("예약 완료!\n");
      clear_buf();
      free(reserved_index);
    }

    if (input_alpha == 'e') {
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);

      printf("예약된 좌석 목록 : ");
      for (i = 0; i < reserved_count; i++) {
        printf("%d ", colouss_airlines[reserved_index[i]].seat_number);
      }



      int input_seat_number = 0;

      printf("예약을 취소 하는 좌석넘버를 입력하시오 (종료시 q) :");

      while (scanf("%d", &input_seat_number) == 1) {
        int i = 0;
        bool is_reserved_seat = false;
        for (i = 0; i < reserved_count; i++) {
          if (input_seat_number == colouss_airlines[reserved_index[i]].seat_number) {
            is_reserved_seat = true;
          }
        }

        if (!is_reserved_seat) {
          printf("예약되어 있지 않은 좌석입니다.\n");
          printf("다른 예약된 좌석을 입력하시오\n");
          printf("예약을 취소 하는 좌석넘버를 입력하시오 (종료시 q) :");
          continue;
        }
        else {
          break;
        }
      }
      clear_buf();
      for (i = 0; i < 12; i++) {
        if (colouss_airlines[i].seat_number == input_seat_number) {
          colouss_airlines[i].is_resereved = 0;
          strcpy(colouss_airlines[i].reserved_info.firstname, "None");
          strcpy(colouss_airlines[i].reserved_info.lastname, "None");
          break;
        }
      }
      printf("예약 취소 완료!\n");

      free(reserved_index);
      printf("\n");
    }
  }

  /*test_display(colouss_airlines);*/
  printf("프로그램 종료!");

  return 0;
}



int* get_reserved_index(struct seat  colouss_airlines[12])
{
  int i = 0;
  int reserved_count = 0;
  int reserved_index[12] = { 0 };
  for (i = 0; i < 12; i++) {
    if (colouss_airlines[i].is_resereved) {
      reserved_index[reserved_count++] = i;
    }
  }

  int* index_arr = (int*)malloc(sizeof(int) * reserved_count);
  for (i = 0; i < reserved_count; i++) {
    index_arr[i] = reserved_index[i];
  }

  return index_arr;
}

int get_reserved_seat_count(struct seat colouss_airlines[12]) {
  int i = 0;
  int reserved_count = 0;
  int reserved_index[12] = { 0 };
  for (i = 0; i < 12; i++) {
    if (colouss_airlines[i].is_resereved) {
      reserved_count++;
    }
  }

  return reserved_count;
}

void clear_buf()
{
  while (getchar() != '\n') {
    continue;
  }
}

bool init_data(struct seat* pt, char* filename)
{
  FILE* in = (void*)0;
  if ((in = fopen("airline_data.txt", "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
    return false;
  }
  
  while (fscanf(in, "%d %d %s %s\n", &(pt->seat_number), &(pt->is_resereved), pt->reserved_info.firstname, pt->reserved_info.lastname) == 4)  {
    pt++;
  }

  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  return true;
}
