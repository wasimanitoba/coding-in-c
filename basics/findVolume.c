// Wasim Adetunji - Assignment 1 - Wednesday Section
// Finds volume of a sphere with a given radius

#define M_PI 3.14159265358979323846
#define RATIO(4.0 / 3.0)
#include <stdio.h>

#include<math.h>

double power(double base, int exponent) {
  int counter = 1;
  double output = base;
  if (exponent == 0) {
    return 0;
  }
  while (counter < exponent) {

    output *= base;
    counter++;
  }
  return output;
}

int main() {
  double radius = 10;
  double volume = 0;
  volume = RATIO * power(radius, 3) * M_PI;
  printf("The volume of a sphere with a 10 metre radius is %.2lf metres cubed", volume);

}