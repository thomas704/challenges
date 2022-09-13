/*
ID: thomas.56
LANG: C
TASK: ariprog
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, M;
char contains[125001];
int remove_duplicates(int *bisqares, int size) {
  for (int i = 1; i < size; i++) {
    if (bisqares[i - 1] == bisqares[i]) {
      size--;
      for (int j = i; j < size; j++) {
        bisqares[j] = bisqares[j + 1];
      }
    }
  }
  return (size);
}
int compfnc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int compfnc2(const void *a, const void *b) {
  return (*((int *)a + 1) - *((int *)b + 1));
}

int is_in(int n, int *bisqares) {
  int i = N / 2;
  int upper = N + 1;
  int lower = 0;
  while (i < upper && i > lower) {
    if (bisqares[i] == n) {
      return (1);
    } else if (bisqares[i] > n) {
      upper = i;
    } else {
      lower = i;
    }
    i = ((upper - lower) / 2) + lower;
  }
  return (0);
}
int main() {
  FILE *fin = fopen("ariprog.in", "r");
  FILE *fout = fopen("ariprog.out", "w");

  if (fscanf(fin, "%d %d", &N, &M) != 2) {
    exit(1);
  }
  int size = (M + 1) * (M + 1);
  int bisqares[size];
  int count = 0;
  for (int i = 0; i <= M; i++) {
    for (int j = i; j <= M; j++) {
      bisqares[count] = i * i + j * j;
      // printf("%d\n", bisqares[count]);
      count++;
    }
  }
  qsort(&bisqares, count, sizeof(int), compfnc);

  printf("count before: %d\n", count);
  count = remove_duplicates(bisqares, count);
  printf("count after: %d\n", count);
  for (int i = 0; i < count; i++) {
    // printf("%d\n", bisqares[i]);
    // fprintf(fout, "%d\n", bisqares[i]);
    contains[bisqares[i]] = 1;
  }
  int step;
  int inbetween[10000][2];
  int nsols = 0;
  for (int i = 0; i < count; i++) {
    // for every bisqares try every valid sequence
    // printf("start testing from: i=%d   sqare=%d\n", i, bisqares[i]);
    for (int j = i + 1; j < count; j++) {
      step = bisqares[j] - bisqares[i];
      if (step == 0){ // dirty hack for some more duplicates...
        //printf("bisqares[i]=%d   step=%d\n",bisqares[i],step);
        continue;
      }
      // printf("try stepsize=%d\n", step);
      if (bisqares[count] - bisqares[i] < (N - 1) * step) {
        // printf("break for step=%d\n",step);i
        break;
      }
      for (int k = 2; k < N + 2; k++) {
        //printf("bisqares[i]=%d   step=%d   k=%d\n",bisqares[i],step,k);
        //printf("bisqares[i] + step * k = %d\n",bisqares[i] + step * k);
        //printf("contains[]=%d\n",contains[bisqares[i] + step * k]);
        if (contains[bisqares[i] + step * k]) {
          if (k == N - 1) {
            inbetween[nsols][0] = bisqares[i];
            inbetween[nsols][1] = step;
            nsols++;
            break;
          }
        } else {
          break;
        }
      }
      /*
      int n = 1;
      for (int k = j + 1; k < count; k++) {
        //printf("test with: k=%d   sqare=%d   n=%d\n", k, bisqares[k],n);
        if (bisqares[k] == bisqares[i] + (n+1) * step) {
          n++;
          //printf("n=%d\n",n);
          if (n == N-1) {
            /// found one!
            inbetween[nsols][0] = bisqares[i];
            inbetween[nsols][1] = step;
            nsols++;
            //fprintf(fout, "%d %d\n", bisqares[i], step);
            break;
          }
        } else if (bisqares[k] > bisqares[i] + (n+1) * step) {
          n = 1;
          break;
        }
      } */
    }
  }
  if (nsols == 0) {
    fprintf(fout, "NONE\n");
    exit(0);
  }
  qsort(inbetween, nsols, sizeof(inbetween[0]), compfnc2);
  for (int i = 0; i < nsols; i++) {
    // printf("%d %d\n",inbetween[i][0],inbetween[i][1]);
    fprintf(fout, "%d %d\n", inbetween[i][0], inbetween[i][1]);
  }
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
