/**
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 * 
 * 9 = 7 + 2*1^2
 * 15 = 7 + 2*2^2
 * 21 = 3 + 2*3^2
 * 25 = 7 + 2*3^2
 * 27 = 19 + 2*2^2
 * 33 = 31 + 2*1^2
 * 
 * It turns out that the conjecture was false.
 * 
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <stdio.h>
#include <math.h>
#include "helpers.h"

int main(int argc, const char *argv[])
{
  int count = 33;
  int i, tmp0, tmp1, lim, result;

  while (1) {

    count++;

    if ((count % 2 == 0) || (prime(count))) {
      continue;
    }

    for (i = floor(sqrt(count / 2)); i >= 1; i--) {
      tmp0 = 2 * i * i;
      tmp1 = count - tmp0;
      if (prime(tmp1)) {
        //printf("%d, can be written as %d + 2 * %d^2\n", count, tmp1, i);
        break;
      }

      if (i == 1) {
        printf("Result: %d, cannot be written on form x + 2 * y ^ 2;", count);
        return 0;
      }

    }

  }

  return 0;
}
