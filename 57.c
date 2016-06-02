/**
 * It is possible to show that the square root of two can be expressed as an
 * infinite continued fraction.
 *
 * √ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
 *
 * By expanding this for the first four iterations, we get:
 *
 * 1 + 1/2 = 3/2 = 1.5
 * 1 + 1/(2 + 1/2) = 7/5 = 1.4
 * 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 * 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 *
 * The next three expansions are 99/70, 239/169, and 577/408, but the eighth
 * expansion, 1393/985, is the first example where the number of digits in the
 * numerator exceeds the number of digits in the denominator.
 *
 * In the first one-thousand expansions, how many fractions contain a numerator
 * with more digits than denominator?
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  int i, result;
  unsigned long int numerator = 3, denominator = 2;
  unsigned long int num_tmp0, num_tmp1 = 1, den_tmp0, den_tmp1 = 1;
  int num_magnitude, den_magnitude;

  /**
   * The denominator can be derived in series based on the previous value of
   * itself. Looking at the denominator of the initial fractions:
   *
   * 2 + 2 + 1      = 5
   * 5 + 5 + 2      = 12
   * 12 + 12 + 5    = 29
   * 29 + 29 + 12   = 70
   * 70 + 70 + 29   = 169
   * 169 + 169 + 70 = 408
   *
   * Generalising this, the denominator for the i'th expansion is given by the
   * following recursion:
   *
   * n(0) = 1
   * n(1) = 2
   * n(i) = 2 * n(i - 1) + n(i - 2), for i > 1
   *
   * As it turns out, the numerator has the same properties:
   *
   * 3 + 3 + 1      = 7
   * 7 + 7 + 3      = 17
   * 17 + 17 + 7    = 41
   * 41 + 41 + 17   = 99
   * 99 + 99 + 41   = 239
   * 239 + 239 + 99 = 577
   */

  for (i = 0; i < 1000; i++) {
    num_tmp0 = numerator;
    numerator = 2 * numerator + num_tmp1;
    num_tmp1 = num_tmp0;

    num_magnitude = (int)floorl(log10l(numerator));
    printf("%d\n", num_magnitude);

    den_tmp0 = denominator;
    denominator = 2 * denominator + den_tmp1;
    den_tmp1 = den_tmp0;

    den_magnitude = (int)floor(log10(denominator));

    if (num_magnitude > den_magnitude) {
      printf("%lu/%lu\n", numerator, denominator);
      result++;
    }

  }

  printf("Answer: %d\n", result);

  return 0;
}
