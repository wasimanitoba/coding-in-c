// Program to depict a "random walk"
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define MAX_RANDOM_WALK 9
#define MAX_ALPHABET 91#include <time.h>       /* time */


void initialize_number_generator(void) {
  srand((unsigned) time(NULL));
}

int dir_seed(void) {
  int secret_number = rand() % 4;
  return secret_number + 1;
}

int move(int * x, int * y, int dir, int * l, int * r, int * u, int * d) {
  int allBlocked = 0;
  if (( * l) == 1 && ( * d) == 1 && ( * u) == 1 && ( * r) == 1) {
    allBlocked = 1;
  }
  if (allBlocked == 1) {
    printf("All blocked");
    return -1;
  }

  switch (dir) {
  case 1: //left
    if (( * y) < 1) {

      dir = dir_seed();
      return move(x, y, dir, l, r, u, d);
    } //can't go left if array is already at zero
    else {
      * l = * d = * u = 0; //reset to false, all directions clear
      * r = 1; //if we go left, we can't go right
      ( * y) --;
      return dir;
    }
    break;
  case 2: //right
    if (( * y) > 9) {

      dir = dir_seed();
      return move(x, y, dir, l, r, u, d);
    } else {
      * r = * d = * u = 0; //reset to false, all directions clear
      * l = 1; //if we go left, we can't go right

      ( * y) ++;
      return dir;
    }
    break;
  case 3: // up
    if (( * x) < 1) {

      dir = dir_seed();
      return move(x, y, dir, l, r, u, d);
    } else {
      * l = * r = * u = 0; //reset to false, all directions clear
      * d = 1; //if we go left, we can't go right

      ( * x) --;
      return dir;
    }
    break;
  case 4: //down
    if (( * x) > 9) {
      dir = dir_seed();
      return move(x, y, dir, l, r, u, d);
    } else {
      * l = * d = * u = 0; //reset to false, all directions clear
      * r = 1; //if we go left, we can't go right

      ( * x) ++;
      return dir;
    }
    break;

  }

}

int main(void) {

  char walk[10][10];

  int x, y;
  x = y = 0;
  int * startX = & x;
  int * startY = & y;
  int lBlocked = 0;
  int rBlocked = 0;
  int uBlocked = 0;
  int dBlocked = 0; //false
  int * left_blocked = & lBlocked;
  int * right_blocked = & rBlocked;
  int * up_blocked = & lBlocked;
  int * down_blocked = & dBlocked;
  char period = 46;
  int alphabet = 65;
  int boolHolder;
  char tempHolder;
  int prevX;
  int prevY;

  for (int i = 0; i < 10; i++) {

    for (int j = 0; j < 10; j++) {
      walk[i][j] = 46;

    }
  }
  initialize_number_generator();
  walk[0][0] = alphabet;
  do {
    int next = dir_seed();
    prevX = * startX;
    prevY = * startY;

    boolHolder = move(startX, startY, next, left_blocked, right_blocked, up_blocked, down_blocked);
    if (boolHolder == -1 || alphabet > 89) {
      break;
    }

    tempHolder = walk[x][y];
    if (tempHolder == period) {
      walk[x][y] = ++alphabet;

    } else {

      x = prevX;
      y = prevY;
      continue;
    }
  }
  while (boolHolder != -1 && alphabet < MAX_ALPHABET);

  for (int i = 0; i < 10; i++) {

    for (int j = 0; j < 10; j++) {
      printf(" %c", walk[i][j]);

    }
    printf("\n");
  }

}
