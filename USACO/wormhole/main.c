/*
ID: thomas.56
LANG: C
TASK: wormhole
this became one ugly program:
make a struct for the wormholes
then enter the information if wormholes lie one behind the other
then try through all possible wormhole-connection-permutitions, starting at each wormhole until free or in loop
feels like recursion is needed for a pretty solution to create the permutitons
*/
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
struct wormhole {
  int name; // 0,1,...,N-1
  int x;
  int y;
  int con;
  int exithole;
};
int take_nth(int *taken, int n) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (taken[i] == 0) {
      count++;
      if (count > n) {
        taken[i] = 1;
        //printf("take_nth n=%d   i=%d\n",n, i);
        return (i);
      }
    }
  }
  //printf("take_nth n=%d   i=%d\n",n, -1);
  return (-1);
}
int number_free(int *taken) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (taken[i] == 0) {
      count++;
    }
  }
  return (count);
}
// int go_in(int hole, int *history) {}
int try_permut(int *permut, struct wormhole *holes) {
  for (int i = 0; i < N; i = i + 2) {
    holes[permut[i]].con = permut[i + 1];
    holes[permut[i + 1]].con = permut[i];
  }
  printf("permut: ");
  for (int i = 0; i < N; i++) {
    printf("%d  ",permut[i]);
  }
  printf("\n");
  int current;
  int visited[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < N; i++) {
    current = i;
    while (1) {
      current = holes[current].con;
      if (holes[current].exithole == -1) {
        break;
      } else {
        current = holes[current].exithole;
      }
      if (visited[current] == 1) {
        return (1);
      } else {
        visited[current] = 1;
      }
    }
    for (int j = 0; j < N; j++) {
      visited[j] = 0;
    }
  }
  return (0);
}
int main() {
  FILE *fin = fopen("wormhole.in", "r");
  FILE *fout = fopen("wormhole.out", "w");
  if (fscanf(fin, "%d", &N) != 1) {
    exit(1);
  }
  struct wormhole holes[N];

  for (int i = 0; i < N; i++) {
    if (fscanf(fin, "%d %d", &holes[i].x, &holes[i].y) != 2) {
      exit(1);
    }
  }
  int closest_hole = -1;
  int closest_dist = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((holes[i].y == holes[j].y) && (holes[i].x < holes[j].x)) {
        if (closest_dist == 0) {
          closest_dist = holes[j].x - holes[i].x;
          closest_hole = j;
        } else if (closest_dist > holes[j].x - holes[i].x) {
          closest_dist = holes[j].x - holes[i].x;
          closest_hole = j;
        }
      }
    }
    if (closest_hole > -1) {
      holes[i].exithole = closest_hole;
    } else {
      holes[i].exithole = -1;
    }
    closest_dist = 0;
    closest_hole = -1;
  }
  int permut[N];
  int taken[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  int count = 0;
  int loops = 0;
  for (int i = 0; i < N - 1; i++) {
    permut[0] = take_nth(taken, 0);
    permut[1] = take_nth(taken, i);
    count = count + 2;
    if (count == N) {
      loops += try_permut(permut, holes);
    }
    for (int j = 0; j < N - 3; j++) {
      permut[2] = take_nth(taken, 0);
      permut[3] = take_nth(taken, j);
      count = count + 2;
      printf("i=%d, j=%d, count=%d, loops=%d\n", i, j, count, loops);
      if (count == N) {
        loops += try_permut(permut, holes);
      }
      for (int k = 0; k < N - 5; k++) {
        permut[4] = take_nth(taken, 0);
        permut[5] = take_nth(taken, k);
        count = count + 2;
        if (count == N) {
          loops += try_permut(permut, holes);
        }
        for (int l = 0; l < N - 7; l++) {
          permut[6] = take_nth(taken, 0);
          permut[7] = take_nth(taken, l);
          count = count + 2;
          if (count == N) {
            loops += try_permut(permut, holes);
          }
          for (int m = 0; m < N - 9; m++) {
            permut[8] = take_nth(taken, 0);
            permut[9] = take_nth(taken, m);
            count = count + 2;
            if (count == N) {
              loops += try_permut(permut, holes);
            }
            for (int n = 0; n < N - 11; n++) {
              permut[10] = take_nth(taken, 0);
              permut[11] = take_nth(taken, n);
              count = count + 2;
              if (count == N) {
                loops += try_permut(permut, holes);
              }
              count = count - 2;
              taken[permut[10]] = 0;
              taken[permut[11]] = 0;
            }
            count = count - 2;
            taken[permut[8]] = 0;
            taken[permut[9]] = 0;
          }
          count = count - 2;
          taken[permut[6]] = 0;
          taken[permut[7]] = 0;
        }
        count = count - 2;
        taken[permut[4]] = 0;
        taken[permut[5]] = 0;
      }
      count = count - 2;
      taken[permut[2]] = 0;
      taken[permut[3]] = 0;
    }
    count = count - 2;
    taken[permut[0]] = 0;
    taken[permut[1]] = 0;
  }
  printf("loop %d   N = %d   count = %d\n", loops, N, count);
  for (int i = 0; i < N; i++) {
  }

  int nposs = 1;
  for (int N = 2; N < 13; N = N + 2) {
    for (int i = N; i > 2; i = i - 2) {
      // printf("%d %d\n", nposs, i);
      nposs = nposs * (i - 1);
    }
    printf("N=%d   nposs=%d\n", N, nposs);
    nposs = 1;
  }
  fprintf(fout,"%d\n", loops);
  printf("int %d\n", nposs);
  fclose(fin);
  fclose(fout);
  exit(EXIT_SUCCESS);
}
