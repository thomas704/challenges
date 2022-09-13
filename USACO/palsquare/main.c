/*
ID: thomas.56
LANG: C
TASK: palsquare
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
  //printf("num = %d   B = %d\n",num,B);
  int remains[32];
  for (int i = 0; i < 33; i++) {
    remains[i] = num % B;
    //printf("remains: %d\n",remains[i]);
    num = num / B;
    if (num == 0) {
      for (int j = 0; j < i + 1; j++) {
        (*baseB)[j] = inttochar(remains[i - j]);
      }
      (*baseB)[i+1] = '\0';
      //printf("string %s\n",(*baseB));
      break;
    }
  }
}
int check_palindrome(char string[]) {
  //printf("check %s   length=%d\n",string,(int)strlen(string));
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] != string[strlen(string)-1 - i]) {
      //printf("is not\n");
      return (0);
    }
  }
  //printf("is\n");
  return (1);
}

int main() {
  FILE *fin = fopen("palsquare.in", "r");
  FILE *fout = fopen("palsquare.out", "w");
  int B;
  char temp1[32];
  char temp2[32];

  if (fscanf(fin, "%d", &B) != 1) {
    exit(1);
  }
  for (int i = 1; i < 301; i++) {
    make_string(&temp1, i, B);
    make_string(&temp2, i * i, B);
    if (check_palindrome(temp2)) {
      printf("%s %s\n", temp1, temp2);
      fprintf(fout, "%s %s\n", temp1, temp2);
    }
  }
  exit(EXIT_SUCCESS);
}
