/*
ID: thomas.56
LANG: C
TASK: beads
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fin = fopen("beads.in", "r");
  FILE *fout = fopen("beads.out", "w");
  int N = 0;
  char beads[352];
  if (fscanf(fin, "%d %s", &N, &beads[0]) != 2) {
    exit(1);
  }
  printf("number of beads = %d\n", N);
  int max_beads = 0;
  int cbeads = 0;
  for (int i = 0; i < N; i++) {
    if (beads[i] != beads[i + 1]) { // compares to '\0' once
      // potential point to test from i+1 forward and i back
      cbeads = 0;
      // check forward
      char first_color = 'w';
      for (int j = 0; j < N; j++) {
        int index = i + j + 1;
        if (index > N - 1) {
          index = index % N;
        }
        printf("forward cbeads=%d   index=%d   bead=%c\n", cbeads, index,
               beads[index]);
        if (beads[index] == 'r') {
          if (first_color != 'b') {
            first_color = 'r';
            cbeads++;
          } else {
            break;
          }
        } else if (beads[index] == 'b') {
          if (first_color != 'r') {
            first_color = 'b';
            cbeads++;
          } else {
            break;
          }
        } else {
          cbeads++;
        }
      }
      // check backwards
      first_color = 'w';
      for (int j = 0; j < N; j++) {
        int index = i - j;
        if (index < 0) {
          index += N;
        }
        printf("backwards cbeads=%d   index=%d   bead=%c\n", cbeads, index,
               beads[index]);
        if (beads[index] == 'r') {
          if (first_color != 'b') {
            first_color = 'r';
            cbeads++;
          } else {
            break;
          }
        } else if (beads[index] == 'b') {
          if (first_color != 'r') {
            first_color = 'b';
            cbeads++;
          } else {
            break;
          }
        } else {
          cbeads++;
        }
      }
      if (max_beads < cbeads) {
        max_beads = cbeads;
      }
    }
  }
  if (max_beads > N) {
    max_beads = N;
  }
  printf("%d\n", max_beads);
  fprintf(fout, "%d\n", max_beads);
  exit(EXIT_SUCCESS);
}
