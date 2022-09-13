/*
ID: thomas.56
LANG: C
TASK: crypt1
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;

int is_not_in(int test, int (*digits)[]) {
  for (int i = 0; i < N; i++) {
    if (test == (*digits)[i]) {
      return (0);
    }
  }
  return (1);
}
int digit_error(int test, int (*digits)[]) {
  if (test < 0) {
    exit(1);
  }
  while (test) {
    //printf("test %d\n", test % 10);
    if (is_not_in(test % 10, digits)) {
      return (1);
    }
    test = test / 10;
  }

  return (0);
}

int main() {
  FILE *fin = fopen("crypt1.in", "r");
  FILE *fout = fopen("crypt1.out", "w");
  if (fin == NULL || fout == NULL) {
    exit(1);
  }

  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  printf("N=%d\n", N);
  int digits[N];
  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%d", &digits[i]) != 1) {
      exit(1);
    }
    printf("%d ", digits[i]);
  }
  printf("\n");
  int solutions = 0;
  int mult1;
  int mult2;
  int partial1;
  int partial2;
  int product;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
          for (int m = 0; m < N; m++) {
            /// iterate through all 3 and 2 (5) long permutations
            mult1 = (100 * digits[i]) + (10 * digits[j]) + digits[k];
            mult2 = (10 * digits[l]) + digits[m];
            partial1 = digits[m] * mult1;

            partial2 = digits[l] * mult1;

            product = mult1 * mult2;
            //printf("mult1=%d   mult2=%d   partial1=%d   partial2=%d   "
            //       "product=%d\n",
            //       mult1, mult2, partial1, partial2, product);

            if (partial1 > 999) {
              continue;
            } else if (partial2 > 999) {
              continue;
            } else if (product > 9999) {
              continue;
            } else if (digit_error(partial1, &digits)) {
              continue;
            } else if (digit_error(partial2, &digits)) {
              continue;
            } else if (digit_error(product, &digits)) {
              continue;
            } else {
              solutions++;
            }

            /// test if solution and count +1
          }
        }
      }
    }
  }
  printf("%d\n", solutions);
  fprintf(fout, "%d\n", solutions);
  exit(EXIT_SUCCESS);
}
