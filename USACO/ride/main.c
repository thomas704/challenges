/*
ID: thomas.56
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *fin = fopen("ride.in", "r");
  FILE *fout = fopen("ride.out", "w");
  char a[7];
  char b[7];

  if (fscanf(fin, "%s", a) > 6) {
    return (1);
  }
  if (fscanf(fin, "%s", b) > 6) {
    return (1);
  }
  // printf("%s %s\n", a, b);

  int ia = 1;
  int ib = 1;
  int temp = 0;
  for (int i = 0; i < 6; i++) {
    temp = ((int)a[i] - (int)'A' + 1);
    if (temp < 27 && temp > 0) {
      ia *= temp;
      // printf("a: ia=%d\n", ia);
    } else {
      break;
    }
  }
  for (int i = 0; i < 6; i++) {
    temp = ((int)b[i] - (int)'A' + 1);
    if (temp < 27 && temp > 0) {
      ib *= temp;
      // printf("a: ia=%d\n", ia);
    } else {
      break;
    }
  }
  // printf("test %d", (int)'Z' - (int)'A' + 1);
  if ((ia % 47) == (ib % 47)) {
    fprintf(fout, "GO\n");
  } else {
    fprintf(fout, "STAY\n");
  }

  exit(0);
}
