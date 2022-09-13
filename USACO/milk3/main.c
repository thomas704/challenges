/*
ID: thomas.56
LANG: C
TASK: milk3
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bucket {
  int size;
  int milk;
};
struct bucket buckets[3];

struct bucket search(int action){
  /// abbruchbedingunen
  struct bucket hallo;
  return(hallo);
}

int main() {
  FILE *fin = fopen("milk3.in", "r");
  FILE *fout = fopen("milk3.out", "w");

  if (fscanf(fin, "%d %d %d", &buckets[0].size, &buckets[1].size,
             &buckets[2].size) != 3) {
    exit(1);
  }
  buckets[0].milk = 0;
  buckets[1].milk = 0;
  buckets[2].milk = buckets[2].size;

  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
