#include <math.h>
#include <stdlib.h>

#include "helpers.h"

/* greatest common divisor */
int gcd(int a, int b)
{
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

/* least common multiple */
int lcm(int a, int b)
{
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
int pandigital(long n) { // max 4294967295, ten digits
  
  short digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  short magnitude = 0;
  
  while (n > 0) {
    digits[n % 10] = 1;
    n /= 10;
    magnitude++;
  }
  
  short result = 1, i;
  for (i = 0; i < magnitude; i++) { // not counting zero
    //printf("i: %d, di: %d\n", i, digits[i]);
    result &= digits[i];
  }
  
  return result;
}

/**
 * Takes a 10 digit number, n, and returns a new number
 * consisting of n_{x}, n_{x+1}, ..., n_{y-1}, n_{y},
 * where x and y are positions of individual digits in n.
 */
int disect(int n, int x, int y) {
  int nlength = (int)ceil(log10(n));
  if(x <= 0) x = 1;
  if(y <= 0) y = 1;
  if(x > nlength) x = nlength;
  if(y > nlength) y = nlength;
  int tmp0 = n / pow(10, nlength - y);
  int tmp1 = pow(10, y - x + 1);
  int tmp2 = (tmp0 / tmp1) * tmp1;
  return tmp0 - tmp2;
}

/* 2nd degree polynomial solver */
ftuple_t p2_solver(float a, float b, float c)
{
  ftuple_t result;
  float d = pow(b, 2) - 4 * a * c;
  if(d > 0) {
    result.a = (-b + sqrt(d)) / 2 * a;
    result.b = (-b - sqrt(d)) / 2 * a;
  } else if(d == 0) {
    result.a = result.b = (-b + sqrt(d)) / 2 * a;
  } else {
    result.a = result.b = -1;
  }
  return result;
}

/**
 * Returns the factorial of n.
 */
long unsigned int factorial(int n)
{ 
  return n == 0 ? 1 : n * factorial(n - 1);
}


/**
 * Returns the factorial of n. (memoized version)
 */
unsigned int mfactorial(int n)
{
  static int allocated = 0;
  static int *factorials;

  if(n <= allocated)
  {
    return factorials[n];
  }

  if (allocated == 0) { // init
    factorials = malloc(sizeof(int) * 2);
    factorials[0] = factorials[1] = 1;
    allocated = 2;
  }

  // Allocate in large chunks
  if (n > allocated) {
    allocated += 5000;
    factorials = realloc(factorials, sizeof(int) * allocated);
  }

  return n * mfactorial(n - 1);
}
