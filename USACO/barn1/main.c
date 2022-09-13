/*
ID: thomas.56
LANG: C
TASK: barn1
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfnc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  FILE *fin = fopen("barn1.in", "r");
  FILE *fout = fopen("barn1.out", "w");
  int M, S, C;
  if (fscanf(fin, "%d %d %d", &M, &S, &C) != 3) {
    exit(1);
  }
  int stalls[200];
  for (int i = 0; i < C; i++) {
    if (fscanf(fin, "%d", &stalls[i]) != 1) {
      exit(1);
    }
  }
  qsort(stalls, C, sizeof(int), cmpfnc);
  for (int i = 0; i < C; i++) {
    printf("%d   %d\n", i, stalls[i]);
  }
  int covered_arr[S];
  for (int i = 0; i < S; i++) {
    if ((i <= stalls[0]) || (i >= stalls[C - 1])) {
      covered_arr[i] = 0;
    } else {
      covered_arr[i] = 1;
    }
  }
  for (int i = 0; i < C; i++) {
    covered_arr[stalls[i]] = 2;
  }
  /// covered_arr: 0 not covered, 1 covered without, 2 covered with cow
  int biggest_gap_start = 0;
  int biggest_gap_size = 0;
  int gap_start = 0;
  int gap_size = 0;
  int covered = stalls[C - 1] - stalls[0] + 1;
  for (int i = 0; i < M - 1; i++) {
    // find biggest gap
    for (int j = stalls[0]; j <= stalls[C - 1]; j++) {
      if (covered_arr[j] == 1) {
        if (gap_size == 0) {
          gap_start = j;
        }
        gap_size++;
      } else {
        if (gap_size > biggest_gap_size) {
          biggest_gap_size = gap_size;
          biggest_gap_start = gap_start;
        }
        gap_size = 0;
        gap_start = 0;
      }
    }
    printf("biggest_gap_start %d   biggest size %d\n", biggest_gap_start,
           biggest_gap_size);
    if (biggest_gap_size == 22) {
      for (int i = 0; i < S; i++) {
        printf("%d\n", covered_arr[i]);
      }
    }
    for (int j = biggest_gap_start; j < biggest_gap_start + biggest_gap_size; j++) {
      covered_arr[j] = 0;
    }

    printf("covered=%d\n", covered);
    covered = covered - biggest_gap_size;
    biggest_gap_size = 0;
    biggest_gap_start = 0;
    // subtract from covered
  }

  printf("M %d   S %d   C %d\n", M, S, C);
  printf("%d\n", covered);
  for (int i = 0; i < S; i++) {
    // printf("%d\n", covered_arr[i]);
  }
  fprintf(fout, "%d\n", covered);
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
