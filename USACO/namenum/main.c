/*
ID: thomas.56
LANG: C
TASK: namenum
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reorder(char (*names)[5000][13], int items, int letter_num, int letter) {
  char TTR[10][3] = {{'0','0','0'},
                     {'0','0','0'},
                     {'A', 'B', 'C'},
                     {'D', 'E', 'F'},
                     {'G', 'H', 'I'},
                     {'J', 'K', 'L'},
                     {'M', 'N', 'O'},
                     {'P', 'R', 'S'},
                     {'T', 'U', 'V'},
                     {'W', 'X', 'Y'}};
  int new_index = 0;
  for (int i = 0; i < items; i++) {
    if ((*names)[i][letter_num] == TTR[letter][0] ||
        (*names)[i][letter_num] == TTR[letter][1] ||
        (*names)[i][letter_num] == TTR[letter][2]) {
      strcpy((*names)[new_index], (*names)[i]);
      new_index++;
    }
  }
  return (new_index);
}
int main() {
  FILE *fin = fopen("namenum.in", "r");
  FILE *fout = fopen("namenum.out", "w");
  FILE *dict = fopen("dict.txt", "r");
  char S[13];
  if (fscanf(fin, "%s", S) != 1) {
    exit(1);
  }
  char names[5000][13];
  int items = 0;
  while (1) {
    int check = fscanf(dict, "%s", names[items]);
    if (check == EOF) {
      break;
    }
    if (check != 1) {
      exit(1);
    }
    printf("%s\n", names[items]);
    items++;
  }
  printf("items read: %d\n", items);
  printf("%s\n", S);
  int nums[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int letters = 0;
  for (int i = 0; i < 13; i++) {
    if (S[i] == '\0') {
      letters = i;
      printf("letters: %d\n", letters);
      break;
    }
    nums[i] = (int)S[i] - (int)'0';
    printf("%d\n", nums[i]);
  }
  for (int i = 0; i < letters; i++) {
    items = reorder(&names, items, i, nums[i]);
  }
  if (items == 0) {
    printf("NONE\n");
  } else {
    for (int i = 0; i < items; i++) {
      if (names[i][letters] == '\0') {
        printf("%s\n", names[i]);
      }
    }
  }
  if (items == 0) {
    fprintf(fout,"NONE\n");
  } else {
    for (int i = 0; i < items; i++) {
      if (names[i][letters] == '\0') {
        fprintf(fout,"%s\n", names[i]);
      }
    }
  }
  fclose(dict);
  fclose(fout);
  fclose(fin);
  exit(EXIT_SUCCESS);
}
