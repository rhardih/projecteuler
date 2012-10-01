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
 * http://en.wikipedia.org/wiki/Combination
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
 * --------------------------- = ----------- = (8 * 7) = 56
 * (5 * 4 * 3 * 2) * (3 * 2)     (3 * 2)
 */

#include <stdio.h>

#include "helpers.h"

int ncr(n, r) {
  int i, j, result = 1;
  for(i = n, j = 1; i >= n - (r - 1); i--, j++)
  {
    result = (result * i) / j;
  }
  return result;
}

int main(int argc, const char *argv[])
{
  int n, r, sum = 0, _ncr;

  for(n = 23; n <= 100; n++) {
    for(r = 1; r <= n; r++) {
      _ncr = ncr(n, r);
      if(_ncr > 1000000) {
        //printf("%dC%d: %d\n", n, r, _ncr);
        sum++;
      }
    }
  }
  
  printf("5C3: %d\n", ncr(5,3));
  printf("23C10: %d\n", ncr(23,10));
  printf("Result: %d\n", sum);
  return 0;
}
