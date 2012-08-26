#include "helpers.h"

#include "36.h"
#include "problems.h"

#define LIMIT 1000000

char *desc36()
{
  return "The decimal number, 585 = (1001001001)2 (binary), is palindromic in both bases.\n\n"
  "Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n\n"
  "(Please note that the palindromic number, in either base, may not include leading zeros.)";
}

int run36(char *output)
{
  int sum = 0;
  char buf[20];
  
  for (int i = 0; i < LIMIT; i++) {
    if(palindromic10(i) && palindromic2(i)) {
      sprintf(buf, "%i, ",i);
      output = strcat(output, buf);
      sum += i;
    }
  }
  
  return sum;
}

int palindromic10(int n)
{
  int tmp0 = n, tmp1 = 0;
  while(1)
  {
    tmp1 += tmp0 % 10;
    tmp0 /= 10;
    if(tmp0) tmp1 *= 10; else break;
  }
  
  return n == tmp1;
}

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