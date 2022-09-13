/*
ID: thomas.56
LANG: C
TASK: transform
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
void print_a(char s[], char (*a)[10][11]) {
  printf("%s\n", s);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c", (*a)[i][j]);
    }
    printf("\n");
  }
}

int comp_ab(char (*a)[10][11], char (*b)[10][11]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((*a)[i][j] != (*b)[i][j]) {
        return (0);
      }
    }
  }
  return (1);
}

void rotate90(char (*a)[10][11]) {
  char temp[10][11];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      temp[i][j] = (*a)[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      (*a)[j][N - i - 1] = temp[i][j];
    }
  }
}
void copy_a_to_b(char (*a)[10][11], char (*b)[10][11]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      (*b)[i][j] = (*a)[i][j];
    }
  }
}
void mirror_hor(char (*a)[10][11]) {
  char temp[10][11];
  copy_a_to_b(a, &temp);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      (*a)[i][j] = temp[i][(N - j - 1)];
    }
  }
}
int main() {
  FILE *fin = fopen("transform.in", "r");
  FILE *fout = fopen("transform.out", "w");
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  char a[10][11];
  char b[10][11];
  char c[10][11];
  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%s", a[i]) != 1) {
      exit(1);
    }
  }
  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%s", b[i]) != 1) {
      exit(1);
    }
  }
  printf("before copy and mirror to c");
  print_a("a", &a);
  print_a("b", &b);
  print_a("c", &c);
  int answer = 7;
  if (comp_ab(&a, &b)) {
    answer = 6;
  }
  copy_a_to_b(&a, &c);
  mirror_hor(&c);
  printf("after copy and mirror to c");
  print_a("a", &a);
  print_a("b", &b);
  print_a("c", &c);
  if (comp_ab(&b, &c)) {
    answer = 4;
  }
  for (int i = 0; i < 3; i++) {
    rotate90(&a);
    rotate90(&c);
    printf("after %dth rotation\n", i);
    print_a("a", &a);
    print_a("b", &b);
    print_a("c", &c);
    if (comp_ab(&a, &b)) {
      answer = i + 1;
      break;
    } else if (comp_ab(&b, &c)) {
      answer = 5;
      break;
    }
  }

  printf("%d\n", answer);
  fprintf(fout, "%d\n", answer);
  exit(EXIT_SUCCESS);
}
