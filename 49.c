/**
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 * 
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
 * 
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"


/**
 * Returns number of permutations of n and places them in *perms.
 *
 * Expects perms to be [24]
 */
int permutations_4d(int n, int *perms)
{
  int number_of_digits = log10(n) + 1;
  int i, j, k, l;

  int *digits = malloc(sizeof(int) * number_of_digits);
  for (i = number_of_digits - 1; i >= 0; i--) {
    digits[i] = n % 10;
    n /= 10;
  }

  int index = 0;
  for (i = 0; i < number_of_digits; i++) {
    for (j = 0; j < number_of_digits; j++) {
      if(j == i) continue;
      for (k = 0; k < number_of_digits; k++) {
        if(k == i || k == j) continue;
        for (l = 0; l < number_of_digits; l++) {
          if(l == i || l == j || l == k) continue;
          perms[index++] =
          1000 * digits[i] +
          100 * digits[j] +
          10 * digits[k] +
          digits[l];
        }
      }
    }
  }

  return 0;
  
}

int main(int argc, const char *argv[])
{
  int i, j, k, l;
  int perms[24]; // 4!
  int permutation_count;
  int diff0, diff1;
  for (i = 1000; i < 9999; i++) {
    if (prime(i)) {
      permutations_4d(i, perms);
      for (j = 0; j < 24; j++) {
        if(prime(perms[j])) {
          for (k = j + 1; k < 24; k++) {
            if(prime(perms[k])) {
              diff0 = perms[j] - perms[k];
              if (diff0 != 3330) continue;
              for (l = k + 1; l < 24; l++) {
                if(prime(perms[l])) {
                  diff1 = perms[k] - perms[l];
                  if (diff1 != 3330) continue;
                  printf("Numbers: %d, %d, %d all have %d between them.\n", perms[l], perms[k], perms[j], diff0);
                }
              }
            }
          }
        }
      }
    }
  }



  return 0;
}
