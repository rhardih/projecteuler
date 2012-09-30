/**
 * Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
 * 
 * Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
 * Pentagonal	 	Pn=n(3n-1)/2	 	1, 5, 12, 22, 35, ...
 * Hexagonal	 	Hn=n(2n-1)	 	1, 6, 15, 28, 45, ...
 * It can be verified that T285 = P165 = H143 = 40755.
 * 
 * Find the next triangle number that is also pentagonal and hexagonal.
 */

/**
 * Notes
 *
 * The nth pentagonal number is one third of the 3n-1th triangular number.
 * Every hexagonal number is a triangular number, but only every other triangular number (the 1st, 3rd, 5th, 7th, etc.)
 */

#include <stdio.h>
#include <limits.h>

#define T(n) (((n) * (n) + (n)) / 2)
#define P(n) ((3 * (n) * (n) - n) / 2)
//#define H(n) (2 * (n) * (n) - n)

int main(int argc, const char *argv[])
{
  long long n_t = 287, n_p = 165;
  long long tn, pn;

  while (1)
  {
    tn = T(n_t);
    //printf("T(%d) = %d\n", n_t, tn);
    while((pn = P(n_p)) < tn)
    {
      //printf("P(%d) = %d\n", n_p, pn);
      n_p++;
    }
    if(tn == pn)
    {
      printf("tn = %lld\n", tn);
      break;
    }
    n_t += 2;
  }
  
  return 0;
}
