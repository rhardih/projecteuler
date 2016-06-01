/**
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <math.h>
#include <stdio.h>

#include "helpers.h"
#include "35.h"

#define LIMIT 1000000

int main(int argc, const char *argv[])
{

  int cprimes[LIMIT] = { 0 }, i;
  char buf[1000];

  // all primes below 10 is trivially circular
  cprimes[2] = cprimes[3] = cprimes[5] = cprimes[7] = 1;

  // utilize that all primes can be written as 6k +- 1
  for (i = 12; i < LIMIT; i += 6) {
    // only numbers containing 1, 3, 7 and 9 is considered,
    // since rotating a 0, 2, 4, 5, 6, or 8 into the units place,
    // the result will be divisible by 2 or 5.

    if (cprimes[i - 1] = circular_prime(i - 1)) {
      printf("%i\n", i - 1);
    }
    if (cprimes[i + 1] = circular_prime(i + 1)) {
      printf("%i\n", i + 1);
    }
  }

  printf("Result: %d\n", array_sum(cprimes, LIMIT));
  return 0;
}

int circular_prime(int n)
{
  if (invalid_number(n) || !prime(n)) {
    return 0;
  }

  int current_rotation = n, i;

  for (i = 0; i < log10(n); i++) {
    current_rotation = rotate_right(current_rotation);
    if (!prime(current_rotation)) {
      return 0;
    }
  }

  return 1;
}

int invalid_number(int n)
{
  int i;
  int limit = pow(10, (int) log10(n) + 1);

  for (i = 10; i <= limit; i *= 10) {

    int dec = n % i / (i / 10);

    if (dec != 1 && dec != 3 && dec != 7 && dec != 9) {

      return 1;

    }
  }

  return 0;
}
