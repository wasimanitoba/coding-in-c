// Wasim Adetunji 
// Calculate a polynomial for a given input from the user
// Version 2.0 (this was a few years ago so I should run a diff to review the changes made)

#include<stdio.h>

double input()

{

  double x;

  printf("Please tell us what you would like your variable to be \n");

  scanf("%lf", & x);

  printf("\n Your input is %.2lf", x);

  return x;
}

double polynomial(double j)

{

  double a, b, c, d, e, f;

  a = j * 3;
  a += 2;

  b = a * j;

  b -= 5;

  c = b * j;

  c += -1;

  d = c * j;

  d += 7;

  e = d * j;

  f = e - 6;

  return f;

}

int main()

{

  printf("\n Your output is %.2lf", polynomial(input()));

  return 0;

}