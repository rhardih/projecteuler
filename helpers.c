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
 * Returns whether n is a 0-9 pandigital number
 */
int pandigital(long n) { // max 4294967295, ten digits

  short digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  short magnitude = 0;

  while (n > 0) {
    digits[n % 10] = 1;
    n /= 10;
    magnitude++;
  }

  if(digits[0]) return 0;

  short result = 1, i;
  for (i = 1; i < magnitude + 1; i++) { // not counting zero
    /*printf("i: %d, di: %d\n", i, digits[i]);*/
    result &= digits[i];
  }

  return result;
}

/**
 * Returns whether n is a 0-9 pandigital number
 * O(log(n))
 *
 * It works by setting the bit at position x to one
 * if x is part a digit in the number n.
 *
 * Checking if a digit has already been encountered in n,
 * is done by xoring the digit bit into place. If it was
 * already set, the bit will then be zero and the value
 * of the number must have decreased.
 */
int pandigital09(long n) { // max 4294967295, ten digits
  int mask = 0, tmp;

  while (n > 0) {
    tmp = mask ^ (1 << (n % 10));
    if(tmp < mask) return 0;
    mask = tmp;
    n /= 10;
  }

  return mask == 0x3FF;
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
 * Factorial of n, recursive
 */
long unsigned int recursive_factorial(int n)
{
  return n == 0 ? 1 : n * recursive_factorial(n - 1);
}

long unsigned int lfactorial(int n, int lower) {
  long unsigned int result = n;
  while(n > lower) {
    n--;
    result *= n;
  }
  return result;
}

/**
 * Factorial of n, looping
 *
 * 2^64    = 18446744073709551615
 * fac(20) = 2432902008176640000
 */
long unsigned int loopfactorial(int n) {
  if(n == 1 || n == 0) return 1;

  long unsigned int result = n;
  while(n > 2)
  {
    result *= --n;
  }
  return result;
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

/**
 *  Returns the number resulting from reversing the order of the digits of n.
 */
long long unsigned int reverse(long long unsigned int n) {
  long long unsigned int tmp = 0;

  while(n > 0) {
    tmp *= 10;
    tmp += n % 10;
    n /= 10;
  }

  return tmp;
}

/**
 * Returns whether n is a palindromic number
 */
int palindromic10(long long unsigned int n)
{
  return n == reverse(n);
}
