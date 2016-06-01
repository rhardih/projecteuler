#include <stdio.h>
#include <stdarg.h>
#include "helpers.h"

int main(int argc, char const *argv[])
{
  printf("\n");
  // n: nominator, d: denominator
  int n, d, result_n = 1, result_d = 1;
  for (d = 11; d < 99; d++) {
    for (n = 10; n < d; n++) {
      int ones_of_n = n % 10;
      int tens_of_n = (n - ones_of_n) / 10;

      int ones_of_d = d % 10;
      int tens_of_d = (d - ones_of_d) / 10;

      if (ones_of_n != tens_of_n &&
          ones_of_d != tens_of_d &&
          (ones_of_n == tens_of_d || tens_of_n == ones_of_d)) {
        float fraction_value = (float) n / (float) d;

        float mix1 = (float) ones_of_n / (float) tens_of_d;

        if (mix1 == fraction_value) {
          printf("%d/%d - %d/%d\n", n, d, ones_of_n, tens_of_d);
          result_n *= ones_of_n;
          result_d *= tens_of_d;
        }

        float mix2 = (float) tens_of_n / (float) ones_of_d;

        if (mix2 == fraction_value) {
          printf("%d/%d - %d/%d\n", n, d, tens_of_n, ones_of_d);
          result_n *= tens_of_n;
          result_d *= ones_of_d;
        }
      }
    }
  }

  int _gcd = gcd(result_n, result_d);
  result_n /= _gcd;
  result_d /= _gcd;

  printf("result: %d/%d\n", result_n, result_d);
  return 0;
}
