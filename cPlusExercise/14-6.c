#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 11
#pragma warning(disable : 4996)

typedef struct {
  char name[4];
  int at_bats;
  int hits;
  int walks;
  int rbis;
} hitter_data;

typedef struct {
  char name[4];
  int at_bats;
  int hits;
  int walks;
  int rbis;
  float rates;
} hitter;

///�����͸� ������� KT�迭�� �ʱ�ȭ(�̸���)
void group_init(hitter* pt, char* filename);
void insert_data(hitter* pt, char* filename, const int size);
///�����͸� �ϳ��� ������ ��ġ�� �̸����� �����ϴ� �Լ� �迭�� �������� �ʴ�
///�̸��� ��� �߰���
bool read_init_validate_data(hitter* pt, char* filename, int index);

void get_group_data(const hitter* pt);
void calculate_rates(hitter* pt);
int main(void) {

  hitter KT[11] = { 0 };

  group_init(KT, "game_data.txt");
  insert_data(KT, "game_data.txt", N);
  calculate_rates(KT);
  get_group_data(KT);
}

void group_init(hitter* pt, char* filename) {
  int i = 0;
  while (i < N) {
    if (read_init_validate_data(pt, filename, i)) {
      continue;
    }
    else {
      i++;
    }
  }
}

bool read_init_validate_data(hitter* pt, char* filename, int index) {
  static FILE* in = (void*)0;
  char tmp_name[4];
  if (!in && (in = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  fscanf(in, "%s %*c %*c %*c %*c\n", tmp_name);

  bool is_in = false;

  for (int i = 0; i < 11; i++) {
    if (strcmp(pt[i].name, tmp_name) == 0)
      is_in = true;
  }

  if (!is_in) {
    strcpy(pt[index].name, tmp_name);
  }

  return is_in;
}

void insert_data(hitter* pt, char* filename, const int size) {
  FILE* in = (void*)0;
  hitter_data tmp_data = { 0 };
  if ((in = fopen("game_data.txt", "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  while (fscanf(in, "%s %d %d %d %d\n", tmp_data.name, &tmp_data.at_bats,
    &tmp_data.hits, &tmp_data.walks, &tmp_data.rbis) == 5) {
    ///���������� �����͸� ���� ��

    ///�̸��� �´� �ε����� ã�� �� �� �ε����� �����Ͽ� ������ acc ���ش�.

    int i = 0, index = 0;
    bool is_in = false;
    for (i = 0; i < N; i++) {
      if (strcmp(pt[i].name, tmp_data.name) == 0) {
        is_in = true;
        break;
      }
      index += 1;
    }
    /// index�� ã�� ��

    if (!is_in) {
      printf("%s�̸��� ���� ������ �������� �ʽ��ϴ�.", tmp_data.name);
    }
    else {
      pt[i].at_bats += tmp_data.at_bats;
      pt[i].hits += tmp_data.hits;
      pt[i].walks += tmp_data.walks;
      pt[i].rbis += tmp_data.rbis;
    }
  }
  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }
}

// typedef struct {
//   char name[4];
//   int hits;
//   int walks;
//   int rbis;
// } hitter_data;

void calculate_rates(hitter* pt) {
  /// 11�� ��ȸ�ϸ鼭 �� ����ü�� ��Ÿ�� / Ÿ���� �� ���� rates�� �������ش�.
  int i = 0;
  for (i = 0; i < N; i++) {

    if (pt[i].at_bats == 0)
      continue;
    else
      pt[i].rates = (float)pt[i].hits / pt[i].at_bats;
  }
}

void get_group_data(const hitter* pt) {
  int i = 0;
  while (i < N) {
    printf("%s %d %d %d %d %.5f\n", pt[i].name, pt[i].at_bats, pt[i].hits,
      pt[i].walks, pt[i].rbis, pt[i].rates);
    i++;
  }
}