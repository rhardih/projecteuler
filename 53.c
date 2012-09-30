/**
 * There are exactly ten ways of selecting three from five, 12345:
 * 
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 * 
 * In combinatorics, we use the notation, 5C3 = 10.
 * 
 * In general,
 * 
 * nCr =	n! / r!(n - r)! , where r <= n, n! = n * (n - 1) * ... * 3 * 2 * 1, and 0! = 1.
 * It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 * 
 * How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100,
 * are greater than one-million?
 *
 * Notes:
 *
 * r is always <= n. When r = n, nCr = 1.
 *
 * It isn't necessary to calculate the factorial of the full value of n, which would
 * be too big.
 *
 * E.g.
 *
 * n = 8
 * r = 5
 *
 * (8 * 7 * 6 * 5 * 4 * 3 * 2)   (8 * 7 * 6)
 * --------------------------- = -----------
 * (5 * 4 * 3 * 2) * (3 * 2)     (3 * 2)
 */

#include <stdio.h>

#include "helpers.h"

int main(int argc, const char *argv[])
{
  int n, r, _gcd, sum;
  int tmpn, tmpr;
  long unsigned int ncr;
  long unsigned int l = 0;

  for(n = 23; n <= 65; n++) {
    for(r = 10; r < n; r++) {
      printf("n: %d, r: %d, n - r: %d\n", n, r, n - r);
      ncr = lfactorial(n, n - r + 1) / factorial(n - r);
      if(ncr > 1000000) {
        if(ncr > l) {
          printf("ncr: %lu\n", l = ncr);
        }
        sum++;
      }
    }
  }
  
  printf("l: %lu\n", l);
  printf("Result: %d\n", sum);
  return 0;
}
