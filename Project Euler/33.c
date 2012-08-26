#include "helpers.h"
#include "problems.h"

char *desc33()
{
  return "The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.\n\n"  
  "We shall consider fractions like, 30/50 = 3/5, to be trivial examples.\n\n"  
  "There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.\n\n"  
  "If the product of these four fractions is given in its lowest common terms, find the value of the denominator.";
}

int run33(char *output)
{
  char buf[1000];
  // n: nominator, d: denominator
  int n, d, result_n = 1, result_d = 1;
  for(d = 11; d < 99; d++)
  {
    for(n = 10; n < d; n++)
    {
      int ones_of_n = n % 10;
      int tens_of_n = (n - ones_of_n) / 10;
      
      int ones_of_d = d % 10;
      int tens_of_d = (d - ones_of_d) / 10;
      
      if(ones_of_n != tens_of_n &&
         ones_of_d != tens_of_d &&
         (ones_of_n == tens_of_d ||
          tens_of_n == ones_of_d))
      {
        float fraction_value = (float)n / (float)d;
        
        float mix1 = (float)ones_of_n / (float)tens_of_d;
        
        if(mix1 == fraction_value)
        {
          sprintf(buf, "%s%d/%d - %d/%d\n", output, n, d, ones_of_n, tens_of_d);
          sprintf(output, "%s", buf);
          result_n *= ones_of_n;
          result_d *= tens_of_d;
        }
        
        float mix2 = (float)tens_of_n / (float)ones_of_d;
        
        if(mix2 == fraction_value)
        {
          sprintf(buf, "%s%d/%d - %d/%d\n", output, n, d, tens_of_n, ones_of_d);
          sprintf(output, "%s", buf);
          result_n *= tens_of_n;
          result_d *= ones_of_d;
        }
      }
    }
  }
  
  int _gcd = gcd(result_n, result_d);
  result_n /= _gcd;
  result_d /= _gcd;
  
  return result_d;
}