/**
 * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 * 
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, const char *argv[])
{
  int digits0[10];
  int digits1[10];
  unsigned int num = 2;
  unsigned int tmp0, tmp1;
  int i, j;
  int all_match;

  while(1)
  {
    tmp0 = num;
    memset(digits0, 0, sizeof(int) * 10);
    while(tmp0)
    {
      digits0[tmp0 % 10]++;
      tmp0 /= 10;
    }
    all_match = 1;
    for (i = 2; i <= 6; i++) {
      tmp1 = num * i;
      memset(digits1, 0, sizeof(int) * 10);
      while(tmp1)
      {
        digits1[tmp1 % 10]++;
        tmp1 /= 10;
      }
      if(memcmp(digits0, digits1, sizeof(int) * 10) != 0)
      {
        all_match = 0;
        break;
      }
    }
    if(all_match) {
      printf("Result: %d\n", num);
      break;
    }
    num++;
  }

  return 0;
}
