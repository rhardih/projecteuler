/**
 * The first two consecutive numbers to have two distinct prime factors are:
 * 
 * 14 = 2 * 7
 * 15 = 3 * 5
 * 
 * The first three consecutive numbers to have three distinct prime factors are:
 * 
 * 644 = 2^2 * 7 * 23
 * 645 = 3 * 5 * 43
 * 646 = 2 * 17 * 19.
 * 
 * Find the first four consecutive integers to have four distinct PRIMES factors. What is the first of these numbers?
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "primes.h"

#define SEARCH_RANGE 200000

/**
 * Returns the number of prime factors of n and fill arr with the actual factors.
 * 
 * Returns 0 if searching for unlisted prime.
 */
int prime_factorize(int n, int *arr)
{ 
  int prime_index = 0;
  int factor_index = 0;
  while(n > 1)
  {
    if (n % PRIMES[prime_index] == 0) {
      arr[factor_index++] = PRIMES[prime_index];
      n /= PRIMES[prime_index];
    }
    else
    {
      prime_index++;
      if (prime_index > PRIME_COUNT - 1) {
        return 0;
      }
    }
  }
  return factor_index;
}

int main(int argc, const char *argv[])
{
  // Guess of 16 or less factors, from the observation that
  // the number of prime divisors of n for n <= 10^5, the maximum is 16
  // 2^16 = 65536 or
  // 2^15 * 3 = 98304
  int *arr = calloc(16, sizeof(int));
  int h, i, j;
  int count, countd;
  int accepted;
  char buf0[500];
  char buf1[500];
  for (h = 647; h < SEARCH_RANGE; h += 4) {
    accepted = 0;
    buf0[0] = buf1[0] = 0;
    for (i = 0; i < 4; i++) {
      count = prime_factorize(h + i, arr);
      countd = 0;
      sprintf(buf1, "%s%d has %d factors in all:\n", buf0, h + i, count);
      for (j = 0; j < count; j++) {
        if (arr[j - 1] != arr[j]) {
          countd++;
        }
        sprintf(buf0, "%s%d\n", buf1, arr[j]);
        sprintf(buf1, "%s", buf0);
      }
      if (countd == 4) {
        accepted++;
        sprintf(buf0, "%sFrom %d distinct factors.\n", buf1, countd);
      }
    }
    if (accepted == 4) {
      printf("%s\nResult: %d\n", buf0, h);
      break;
    }
  }

  return 0;
}
