/*
ID: thomas.56
LANG: C
TASK: combo
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
struct combo {
  int a;
  int b;
  int c;
} john, master;

int is_equal(struct combo one, struct combo two) {
  if ((one.a == two.a) && (one.b == two.b) && (one.c == two.c)) {
    return (1);
  }
  return (0);
}
void make_valid_combos(struct combo *from, struct combo (*dest)[125]) {
  int l = 0;
  for (int i = -2; i < 3; i++) {
    for (int j = -2; j < 3; j++) {
      for (int k = -2; k < 3; k++) {
        (*dest)[l].a = from->a + i;
        if ((*dest)[l].a < 1) {
          (*dest)[l].a += N;
        } else if ((*dest)[l].a > N) {
          (*dest)[l].a -= N;
        }
        (*dest)[l].b = from->b + j;
        if ((*dest)[l].b < 1) {
          (*dest)[l].b += N;
        } else if ((*dest)[l].b > N) {
          (*dest)[l].b -= N;
        }
        (*dest)[l].c = from->c + k;
        if ((*dest)[l].c < 1) {
          (*dest)[l].c += N;
        } else if ((*dest)[l].c > N) {
          (*dest)[l].c -= N;
        }
        //printf("%d %d %d\n", (*dest)[l].a, (*dest)[l].b, (*dest)[l].c);
        l++;
      }
    }
  }
}
int main() {
  FILE *fin = fopen("combo.in", "r");
  FILE *fout = fopen("combo.out", "w");
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  if (fscanf(fin, "%d %d %d %d %d %d", &john.a, &john.b, &john.c, &master.a,
             &master.b, &master.c) != 6) {
    exit(1);
  }
  if (N < 6) {
    fprintf(fout, "%d\n", N * N * N);
    exit(0);
  }
  struct combo johns[125], masters[125];
  make_valid_combos(&john, &johns);
  make_valid_combos(&master, &masters);
  int valid = 250;
  for (int i = 0; i < 125; i++) {
    for (int j = 0; j < 125; j++) {
      printf("is equal?:\n%d %d %d   %d %d %d\n",johns[i].a,johns[i].b,johns[i].c,masters[j].a,masters[j].b,masters[j].c);
      if (is_equal(johns[i], masters[j])) {
        // printf("is equal:\n%d %d %d   %d %d
        // %d\n",johns[i].a,johns[i].b,johns[i].c,masters[j].a,masters[j].b,masters[j].c);
        valid--;
      }
    }
  }
  fprintf(fout, "%d\n", valid);
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
