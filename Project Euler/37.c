#include <limits.h>

#include "37.h"
#include "problems.h"

#include "helpers.h"

char *desc37()
{
  return "The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.\n\n"
  "Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n\n"
  "NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.";
}

int run37(char *output)
{
  int sum = 23;
  char tmp[1000];
  int count = 10;
  
  // Listing the prime numbers, it can be seen that 37 is the first to fit
  // our criteria, since both 3 and 7 is prime.
  // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
  int current = 23; // eleven primes to find, 11 is trivially correct
  sprintf(output, "%i\n", current);
  
  while (count) {
    current++;
    if(all_cuts_prime(current)) {
      count--;
      sum += current;
      sprintf(tmp, "%s%i\n", output, current);
      sprintf(output, "%s", tmp);
    }
  }
  
  return sum;
}

/* Finds whether or not a number is prime and truncatable from both left and
 * right. */
int all_cuts_prime(int n) {
  
  if (!prime(n)) {
    return 0;
  }
  
  int i = n;
  
  while ((i = cut_left(i))) {
    if (!prime(i)) {
      return 0;
    }
  }
  
  i = n;
  
  while ((i = cut_right(i))) {
    if (!prime(i)) {
      return 0;
    }
  }
  
  return 1;
}

/* Returns the number that is left when removing the leftmost digit.
 * E.g. 3797 -> 797 */
int cut_left(int n) {
  int magnitude = (int)log10(n);
  return (int)(n % (int)pow(10, magnitude));
}

/* Returns the number that is left when removing the rightmost digit.
 * E.g. 3797 -> 379 */
int cut_right(int n) {
  return n / 10;
}