/**
 * By replacing the 1st digit of *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 * 
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
 * 
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "primes.100k.h"

int main(int argc, const char *argv[])
{
  int i, j, k, l;
  int count = 0;
  int magnitude;
  int tmp0, tmp1, tmp2;
  int *digits = calloc(10, sizeof(int));
  int mark = 0;
  char buf0[10];
  int family_size;

  for (i = 0; i < PRIME_COUNT; i++) {
    tmp0 = PRIMES[i];
    while (tmp0) {
      digits[tmp0 % 10]++;
      tmp0 /= 10;
    }
    for (j = 0; j < 10; j++) {
      if(digits[j] > 1) {
        family_size = 1;
        for (k = 1; k < 10; k++) {
          sprintf(buf0, "%d", PRIMES[i]);
          // replace all of that digit with 0-9
          magnitude = (int)log10(PRIMES[i]) + 1;
          for (l = 0; l < magnitude; l++) {
            tmp1 = buf0[l] - 48; // 48 is ascii value for '0'
            if (tmp1 == j) {
              buf0[l] = ((tmp1 + k) % 10) + 48;
            }
          }
          sscanf(buf0, "%d", &tmp2);
          // Check magnitude in case a 0 was most significant
          // making a smaller number but still prime
          if ((int)log10(tmp2) + 1 == magnitude && prime(tmp2)) {
            family_size++;
          }
        }
        if(family_size == 8) {
          printf("%d\n", PRIMES[i]);
          return 0;
        }
      }
      digits[j] = 0;
    }
  }
  return 0;
}
