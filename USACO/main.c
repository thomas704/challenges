/*
ID: thomas.56
LANG: C
TASK: template
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fin = fopen("template.in", "r");
  FILE *fout = fopen("template.out", "w");
  int N;
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
