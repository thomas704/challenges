/*
ID: thomas.56
LANG: C
TASK: milk2
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  FILE *fin = fopen("milk2.in", "r");
  FILE *fout = fopen("milk2.out", "w");
  int N;
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  int schedule[N][2];
  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%d %d", &schedule[i][0], &schedule[i][1]) != 2) {
      exit(1);
    }
  }
  qsort(schedule, N, sizeof(int[2]), cmpfunc);
  int current_start = schedule[0][0];
  int current_end = schedule[0][1];
  int max_milk = 0;
  int max_idle = 0;
  for (int i = 1; i < N; i++) {

    if (schedule[i][0] <= current_end) {
      current_end = MAX(schedule[i][1], current_end);
    } else {
      max_milk = MAX(max_milk, current_end - current_start);
      max_idle = MAX(max_idle, schedule[i][0] - current_end);
      current_start = schedule[i][0];
      current_end = schedule[i][1];
    }
  }

  max_milk = MAX(max_milk, current_end - current_start);
  fprintf(fout, "%d %d\n", max_milk, max_idle);
  exit(EXIT_SUCCESS);
}
