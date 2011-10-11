#include <math.h>

#include "helpers.h"

/* greatest common divisor */
int gcd(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

/* least common multiple */
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

/* Indicates whether n is prime.
 * 
 * Utilises the fact that all primes p > 3 are of the form 6n +- 1 */
int prime(int n)
{
  if ((n != 2 && n != 3) &&
      (n == 1 || n % 2 == 0 || n % 3 == 0)) {
    return 0;
  }
  else {
    double sr = sqrt(n);
    int i;
    for (i = 6; i - 1 <= sr; i += 6) {
      if ((n % (i - 1)) == 0 ||
          (n % (i + 1)) == 0) {
        return 0;
      }
    }
  }
  
  return 1;
}

// sums all elements of an integer array
int array_sum(int *arr, int len)
{
  int i, result = 0;
  for(i = 0; i < len; i++)
  {
    result += arr[i];
  }
  return result;
}

/* rotates a number one digit to the right  eg. 123 -> 312 */
int rotate_right(int n)
{
  int ones = n % 10;
  int decimated = n / 10;
  int magnitude = log10(n);
  return (ones * pow(10, magnitude)) + decimated;
}

/**
 * Returns whether n is square
 */
int square(int n)
{ 
    int root = sqrt(n);
    return root * root == n;
}

/**
 * Returns whether n is a pandigital number
 * O(log(n)) 
 */
int pandigital(unsigned int n) { // max 4294967295, ten digits
  
  short digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  short magnitude = 0;
  
  while (n > 0) {
    digits[n % 10] = 1;
    n /= 10;
    magnitude++;
  }
  
  short result = 1, i;
  for (i = 1; i <= magnitude; i++) { // not counting zero
    result &= digits[i];
  }
  
  return result;
}
