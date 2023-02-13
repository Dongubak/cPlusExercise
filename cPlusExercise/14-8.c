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

//seat_number : ������ => �¼���ȣ
//is_reserved : bool�� => �¼���������
//reserved_info.firstname : ���ڿ� => ������ �Ǿ��ִٸ� �������� ��
//reserved_info.lastname : ���ڿ� => ������ �Ǿ��ִٸ� �������� �̸�

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
  printf("a)��� �ִ� �¼� �� ǥ��  b)��� �ִ� �¼� ��� ǥ��   c)����� �¼��� �� �̸��� ���ĺ� ������ ǥ��\n");
  printf("d)�¼� ����             e)���� ���                 f)���α׷� ����\n");
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
      printf("����ִ� �¼� �� : %d\n", 12 - get_reserved_seat_count(colouss_airlines));
    }

    if (input_alpha == 'b') {
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);
      printf("����ִ� �¼� ��� : ");

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
      ///����ִ� �¼� ����� �����ش�.
      ///���ϴ� �¼��� ��ȣ�� �Է��ϰ� �Ѵ�. �̶� �Է��� ����� �� �־�� �Ѵ�.
      ///�������� �¼���ȣ�� �Է��� ��� ������ �����Ѵ�.
      ///�������� �Է��� �ƴ� ���(�ùٸ� �¼���ȣ�� �Է����� ���� ���) ���� �޼����� ����Ѵ�.
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);
      printf("����ִ� �¼� ��� : ");

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

      printf("�����ϰ��� �ϴ� �¼��ѹ��� �Է��Ͻÿ� (����� q) :");

      while (scanf("%d", &input_seat_number) == 1) {
        int i = 0;
        bool is_reserved_seat = false;
        for (i = 0; i < reserved_count; i++) {
          if (input_seat_number == colouss_airlines[reserved_index[i]].seat_number) {
            is_reserved_seat = true;
          }
        }

        if (is_reserved_seat) {
          printf("�̹� ����� �¼��Դϴ�.\n");
          printf("�ٸ� �¼��� �������ּ���.\n");
          printf("�����ϰ��� �ϴ� �¼��ѹ��� �Է��Ͻÿ� (����� q) :");
          continue;
        }
        else {
          break;
        }
      }


      struct seat new_reserver;
      clear_buf();
      printf("�������� ���� �Է��Ͻÿ�. : ");
      scanf("%s", new_reserver.reserved_info.firstname);

      printf("�������� �̸��� �Է��Ͻÿ� : ");
      scanf("%s", new_reserver.reserved_info.lastname);

      new_reserver.is_resereved = true;
      new_reserver.seat_number = input_seat_number;

      for (i = 0; i < 12; i++) {
        if (colouss_airlines[i].seat_number == input_seat_number) {
          colouss_airlines[i] = new_reserver;
        }
      }
      printf("���� �Ϸ�!\n");
      clear_buf();
      free(reserved_index);
    }

    if (input_alpha == 'e') {
      int i = 0, j = 0;
      int* reserved_index = get_reserved_index(colouss_airlines);
      int reserved_count = get_reserved_seat_count(colouss_airlines);

      printf("����� �¼� ��� : ");
      for (i = 0; i < reserved_count; i++) {
        printf("%d ", colouss_airlines[reserved_index[i]].seat_number);
      }



      int input_seat_number = 0;

      printf("������ ��� �ϴ� �¼��ѹ��� �Է��Ͻÿ� (����� q) :");

      while (scanf("%d", &input_seat_number) == 1) {
        int i = 0;
        bool is_reserved_seat = false;
        for (i = 0; i < reserved_count; i++) {
          if (input_seat_number == colouss_airlines[reserved_index[i]].seat_number) {
            is_reserved_seat = true;
          }
        }

        if (!is_reserved_seat) {
          printf("����Ǿ� ���� ���� �¼��Դϴ�.\n");
          printf("�ٸ� ����� �¼��� �Է��Ͻÿ�\n");
          printf("������ ��� �ϴ� �¼��ѹ��� �Է��Ͻÿ� (����� q) :");
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
      printf("���� ��� �Ϸ�!\n");

      free(reserved_index);
      printf("\n");
    }
  }

  /*test_display(colouss_airlines);*/
  printf("���α׷� ����!");

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
