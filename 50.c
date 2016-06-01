/**
 * The prime 41, can be written as the sum of six consecutive primes:
 * 
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 * 
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 * 
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

#include <stdio.h>

#include "helpers.h"
#include "primes.10k.h"

#define MAX_TERMS 1000
#define MAX_PRIMES 2000

int print_matrix(int w, int h, int matrix[][MAX_TERMS])
{
  int x, y;
  for (y = 0; y < h; y++) {
    printf("[ %d", matrix[y][0]);
    for (x = 1; x < w; x++) {
      printf(" ,%d", matrix[y][x]);
    }
    printf(" ]\n");
  }
  return 0;
}

int main(int argc, const char *argv[])
{
  int prime_sums[MAX_PRIMES][MAX_TERMS];
  int i, j, k;
  int sum = 0;
  int most_terms = 0;
  int most_terms_prime;

  // Fill out a table of sums, where n(x, y) is the sum of the y prime and x previous
  // primes
  //
  // [ 2 ,-1 ,-1 ,-1 ]
  // [ 3 ,5 ,-1 ,-1 ]
  // [ 5 ,8 ,10 ,-1 ]
  // [ 7 ,12 ,15 ,17 ]
  for (i = 0; i < MAX_PRIMES; i++) {
    prime_sums[i][0] = PRIMES[i];
    for (j = 1; j < MAX_TERMS; j++) {
      if (i - j < 0) {
        prime_sums[i][j] = -1;
      } else {
        prime_sums[i][j] = prime_sums[i][j - 1] + prime_sums[i - j][0];
        if (prime(prime_sums[i][j]) &&
            prime_sums[i][j] < 1000000 && j > most_terms) {
          most_terms = j + 1;
          most_terms_prime = prime_sums[i][j];
        }
      }
    }
  }

  printf("Result: %d with %d terms.\n", most_terms_prime, most_terms);

  return 0;
}
