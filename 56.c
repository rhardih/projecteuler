/**
 * A googol (10^100) is a massive number: one followed by one-hundred zeros;
 * 100^100 is almost unimaginably large: one followed by two-hundred zeros.
 * Despite their size, the sum of the digits in each number is only 1.
 * 
 * Considering natural numbers of the form, a^b, where a, b < 100, what is the
 * maximum digital sum?
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

unsigned long int sum_of_digits(mpz_t n)
{
  unsigned long int sum = 0, remainder;

  mpz_t x;
  mpz_init_set(x, n);

  while (mpz_cmp_ui(x, 0) > 0) {
    remainder = mpz_tdiv_ui(x, 10);

    // Subtract remainder to be exactly divisible by 10
    // otherwise mpz_divexact_ui produces undefined results
    mpz_sub_ui(x, x, remainder);
    mpz_divexact_ui(x, x, 10);

    sum += remainder;
  }

  mpz_clear(x);

  return sum;
}

int main(int argc, char const *argv[])
{
  int i, err;
  unsigned long int j, sum, max_sum = 0, res;

  mpz_t n, base, r;

  mpz_inits(n, base, r, NULL);

  for (i = 1; i < 100; i++) {
    mpz_set_ui(base, i);

    for (j = 1; j < 100; j++) {
      mpz_pow_ui(n, base, j);

      sum = sum_of_digits(n);

      if (sum > max_sum) {
        max_sum = sum;
      }
    }
  }

  mpz_clears(n, base, r, NULL);

  printf("Answer: %lu\n", max_sum);

  return 0;
}
