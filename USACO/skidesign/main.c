/*
ID: thomas.56
LANG: C
TASK: skidesign
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
int cost = 0;
int get_cost(int *old_hills, int *new_hills) {
  int cost = 0;
  for (int i = 0; i < N; i++) {
    cost += (old_hills[i] - new_hills[i]) * (old_hills[i] - new_hills[i]);
  }
  return (cost);
}
void cut_top(int *top_hills) {
  top_hills[N - 1]--;
  for (int i = N - 2;; i--) {
    if (top_hills[i] <= top_hills[N - 1]) {
      break;
    } else {
      top_hills[i] = top_hills[N - 1];
    }
  }
}
void cut_bot(int *bottom_hills) {
  bottom_hills[0] += 1;
  for (int i = 1;; i++) {
    if (bottom_hills[i] >= bottom_hills[0]) {
      break;
    } else {
      bottom_hills[i] = bottom_hills[0];
    }
  }
}
int compfnc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  FILE *fin = fopen("skidesign.in", "r");
  FILE *fout = fopen("skidesign.out", "w");
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  if (N == 1) {
    fprintf(fout, "%d\n", N);
  }
  int hills[N];
  int top_hills[N];
  int bottom_hills[N];
  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%d", &hills[i]) != 1) {
      exit(1);
    }
  }
  qsort(&hills, N, sizeof(int), compfnc);
  for (int i = 0; i < N; i++) {
    printf("%d ", hills[i]);
    top_hills[i] = hills[i];
    bottom_hills[i] = hills[i];
  }
  printf("\n");
  int difference = hills[N - 1] - hills[0];
  int cost_bot;
  int cost_top;
  int direction = 1; // 0 nach unten, 1 beide, 2 oben
  while (difference > 17) {
    printf("difference=%d   cost=%d\n", difference, cost);
    if (direction < 2) {
      cut_bot(bottom_hills);
    }
    if (direction > 0) {
      cut_top(top_hills);
    }

    cost_bot = get_cost(hills, bottom_hills);
    cost_top = get_cost(hills, top_hills);
    for (int i = 0; i < N; i++) {
      printf("hills=%d top=%d bot=%d\n", hills[i], top_hills[i],
             bottom_hills[i]);
    }
    printf("cost_bot=%d   cost_top=%d\n", cost_bot, cost_top);
    if (cost_bot < cost_top) {
      cut_bot(top_hills);
      direction = 0;
      cost = cost_bot;
    } else {
      cut_top(bottom_hills);
      direction = 2;
      cost = cost_top;
    }
    difference--;
  }
  printf("ende %d\n", cost);
  fprintf(fout,"%d\n",cost);
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
