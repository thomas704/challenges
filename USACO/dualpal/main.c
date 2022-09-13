/*
ID: thomas.56
LANG: C
TASK: dualpal
*/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inttochar(int num) {
  if (num < 10) {
    return ('0' + num);
  } else {
    return ('A' + num - 10);
  }
}
void make_string(char (*baseB)[32], int num, int B) {
  // printf("num = %d   B = %d\n",num,B);
  int remains[32];
  for (int i = 0; i < 33; i++) {
    remains[i] = num % B;
    // printf("remains: %d\n",remains[i]);
    num = num / B;
    if (num == 0) {
      for (int j = 0; j < i + 1; j++) {
        (*baseB)[j] = inttochar(remains[i - j]);
      }
      (*baseB)[i + 1] = '\0';
      // printf("string %s\n",(*baseB));
      break;
    }
  }
}
int check_palindrome(char string[]) {
  // printf("check %s   length=%d\n",string,(int)strlen(string));
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] != string[strlen(string) - 1 - i]) {
      // printf("is not\n");
      return (0);
    }
  }
  // printf("is\n");
  return (1);
}

int main() {
  FILE *fin = fopen("dualpal.in", "r");
  FILE *fout = fopen("dualpal.out", "w");
  int N, S;

  if (fscanf(fin, "%d %d", &N, &S) != 2) {
    exit(1);
  }
  printf("N = %d   S = %d\n",N,S);
  char test[32];
  int palins = 0;
  int numbers_found = 0;
  for (int i = S + 1; 1; i++) {
    for (int j = 2; j < 11; j++) {
      make_string(&test, i, j);
      if (check_palindrome(test)) {
        palins++;
        if (palins > 1) {
          printf("%d\n", i);
          fprintf(fout, "%d\n", i);
          numbers_found++;
          palins = 0;
          break;
        }
      }
    }
    palins = 0;
    if (numbers_found > N-1) {
      exit(EXIT_SUCCESS);
    }
  }
  exit(1);
}
