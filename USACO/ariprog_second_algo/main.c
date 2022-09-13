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


int is_in(int n, int *bisqares, int N) {
  int i = N / 2;
  int upper = N - 1;
  int lower = 0;

  while (i < upper && i > lower) {
    // printf("upper=%d lower=%d i=%d\n",upper,lower,i);
    if (bisqares[i] == n || bisqares[i - 1] == n || bisqares[i + 1] == n) {
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
  }
  int inbetween[10000][2];
  int step;
  int nsols = 0;
  int streak;
  int test;
  for (int i = 1; i <= (bisqares[count - 1]) / (N - 1); i++) {
    step = i;

    // printf("step=%d\n", step);
    for (int j = 0; j < step; j++) {
      streak = 0;
      for (int k = 0; k < bisqares[count - 1]; k++) {
        test = j + step * k;
        // printf("j + step * k : %d + %d * %d = %d\n",j,step,k,test);
        //printf("is in(%d)=%d\n", test, is_in(test, bisqares, count));
        if (test > bisqares[count - 1]) {
          break;
        }

        if (is_in(test, bisqares, count)) {
          streak++;
          //printf("streak=%d\n", streak);
          if (streak >= N) {
            // fprintf(fout, "%d %d\n", test - step * (N - 1), step);
            inbetween[nsols][0] = test - step * (N - 1);
            inbetween[nsols][1] = step;
            nsols++;
          }
        } else {
          streak = 0;
        }
      }
    }
  }

  printf("count=%d\n", count);
  if (nsols == 0) {
    fprintf(fout, "NONE\n");
    exit(0);
  }
  qsort(inbetween, nsols, sizeof(inbetween[0]), compfnc);
  qsort(inbetween, nsols, sizeof(inbetween[0]), compfnc2);
  for (int i = 0; i < nsols; i++) {
    // printf("%d %d\n",inbetween[i][0],inbetween[i][1]);
    fprintf(fout, "%d %d\n", inbetween[i][0], inbetween[i][1]);
  }

  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
