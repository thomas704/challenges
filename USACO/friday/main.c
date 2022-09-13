/*
ID: thomas.56
LANG: C
TASK: friday
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fin = fopen("friday.in", "r");
  FILE *fout = fopen("friday.out", "w");
  int N;
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  printf("years: %d\n", N);
  int thirteens[7] = {0,0,0,0,0,0,0};
  int weekday = 2; // 0 = saturday ... 6 = friday, start on monday
  int day = 1;
  int month = 1;
  int year = 1900;

  while (1) {
    printf("weekday = %d   day = %d   month = %d   year = %d\n", weekday, day,
           month, year);
    if (day == 13) {
      thirteens[weekday]++;
    }
    if (day == 31 && month == 12 && year == 1900 + N - 1) {
      break;
    }
    day++;
    weekday++;
    if (weekday > 6) {
      weekday = 0;
    }
    if (day == 32) {
      day = 1;
      month++;
    } else if (day == 31 &&
               (month == 4 || month == 6 || month == 9 || month == 11)) {
      day = 1;
      month++;
    } else if (month == 2 && day == 29 &&
               !(((year % 4) == 0 && (year % 100) != 0) || (year % 400 == 0))) {
      day = 1;
      month++;
    } else if (month == 2 && day == 30) {
      day = 1;
      month++;
    }
    if (month == 13) {
      month = 1;
      year++;
    }
  }

  fprintf(fout, "%d %d %d %d %d %d %d\n", thirteens[0], thirteens[1],
          thirteens[2], thirteens[3], thirteens[4], thirteens[5], thirteens[6]);
  exit(EXIT_SUCCESS);
}
