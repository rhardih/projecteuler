/**
 * The decimal number, 585 = 1001001001_2 (binary), is palindromic in both
 * bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include
 * leading zeros.)
 */

#define LIMIT 1000000

#include <stdio.h>
#include <string.h>

#include "helpers.h"

int palindromic2(int n)
{
  int tmp0 = n, tmp1 = 0;
  while(1)
  {
    tmp1 |= tmp0 & 1;
    tmp0 >>= 1;
    if(tmp0) tmp1 <<= 1; else break;
  }
  return n == tmp1;
}

int main(int argc, char const *argv[])
{
  int sum = 0;
  char buf[20];
  
  for (int i = 0; i < LIMIT; i++) {
    if(palindromic10(i) && palindromic2(i)) {
      printf("%i, ",i);
      sum += i;
    }
  }

  printf("\n\n");
  printf("Answer: %d\n", sum);
  
  return 0;
}
