/*
ID: thomas.56
LANG: C
TASK: milk
*/
//#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
int cmpfnc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int main() {
  FILE *fin = fopen("milk.in", "r");
  FILE *fout = fopen("milk.out", "w");
  int N, M;
  int offers[5000][2];
  if (fscanf(fin, "%d %d", &N, &M) != 2) {
    exit(1);
  }
  if (N == 0) {
    fprintf(fout,"%d\n", 0);
    exit(EXIT_SUCCESS);
  }
  for (int i = 0; i < M; i++) {
    if (fscanf(fin, "%d %d", &offers[i][0], &offers[i][1]) != 2) {
      exit(1);
    }
  }
  qsort(offers, M, sizeof(int[2]), cmpfnc);
  for (int i = 0; i < M; i++) {
    // printf("offers %d %d\n",offers[i][0],offers[i][1]);
  }
  int sum = 0;
  int missing_milk = N;
  int i = 0;
  while (1) {
    if (missing_milk > offers[i][1]) {
      sum = sum + (offers[i][0] * offers[i][1]);
      missing_milk = missing_milk - offers[i][1];
      // printf("farmer %d   price %d   offer %d   sum %d   missing
      // %d\n",i,offers[i][0],offers[i][1],sum,missing_milk);
    } else {
      sum = sum + missing_milk * offers[i][0];
      // printf("farmer %d   price %d   offer %d   sum %d   missing
      // %d\n",i,offers[i][0],offers[i][1],sum,missing_milk);
      fprintf(fout, "%d\n", sum);
      break;
    }
    i++;
  }
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
