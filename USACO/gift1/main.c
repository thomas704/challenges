/*
ID: thomas.56
LANG: C
TASK: gift1
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char friends[10][16];
int NP = 0;

int friend_number(char *friend) {
  for (int i = 0; i < NP; i++) {
    if (strcmp(friend, friends[i]) == 0) {
      return (i);
    }
  }
  exit(1);
}
int main() {
  FILE *fin = fopen("gift1.in", "r");
  FILE *fout = fopen("gift1.out", "w");

  if (fscanf(fin, "%d", &NP) != 1) {
    exit(1);
  }
  assert((NP < 11) && (NP > 1));
  for (int i = 0; i < NP; i++) {
    if (fscanf(fin, "%s", friends[i]) != 1) {
      exit(1);
    }
  }
  char temp_friend[16];
  int temp_money = 0;
  int nfriends = 0;
  int moneys[NP];
  memset(moneys, 0, sizeof moneys);
  for (int i = 0; i < NP; i++) {
    printf("loop i = %d\n", i);
    if (fscanf(fin, "%s%d%d", temp_friend, &temp_money, &nfriends) != 3) {
      exit(1);
    }
    printf("temp_friend = %s   temp_money = %d   nfriends = %d\n", temp_friend,
           temp_money, nfriends);

    if (nfriends == 0) {
      moneys[friend_number(temp_friend)] += temp_money;
      continue;
    } else {
      moneys[friend_number(temp_friend)] +=
          (temp_money % nfriends) - temp_money;
      for (int j = 0; j < nfriends; j++) {
        if (fscanf(fin, "%s", temp_friend) != 1) {
          exit(1);
        }
        moneys[friend_number(temp_friend)] += temp_money / nfriends;
      }
    }
    int sum_money = 0;
    for (int i = 0; i < NP; i++) {
      printf("%s %d\n", friends[i], moneys[i]);
      sum_money += moneys[i];
    }
    printf("summe = %d\n",sum_money);
  }

  for (int i = 0; i < NP; i++) {
    fprintf(fout, "%s %d\n", friends[i], moneys[i]);
  }
  exit(EXIT_SUCCESS);
}
