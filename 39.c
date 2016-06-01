/**
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 * 
 * {20,48,52}, {24,45,51}, {30,40,50}
 * 
 * For which value of p ≤ 1000, is the number of solutions maximised?
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  // We have the perimeter p and sides a, b, c
  // 
  // p = a + b + c (1)
  // c = p - a - b
  //
  // And for a right angled triangle we have
  // a^2 + b^2 = c^2   (2)
  //
  // Substituting we get
  // a^2 + b^2 = (p - a - b)^2
  // a^2 + b^2 = p^2 + a^2 + b^2 - 2pa - 2pb + 2ab
  // 2pb - 2ab = p^2 - 2pa
  // 2b(p - a) = p^2 - 2pa
  // b = (p^2 - 2pa) / 2(p - a)
  //
  // Also if a and b is even, from (2) c must also be even. Proof:
  //
  // If n = 2k, then n^2 = 4k^2 = 2(2k^2), which is 2 times an integer and 
  // therefore is even. The sum of two even numbers is even. In (1) that makes
  // c^2 even and therefore c even. (3) The sum of 3 even numbers is even and 
  // P must then be even.
  //
  // If a and b is both odd, 
  // n = 2k + 1
  // n^2 = 4k^2 + 4k + 1
  // n^2 = 2(2k^2 + 2k) + 1
  // Since m = 2k^2 + 2k is an integer, you have expressed n^2 as 2m+1, 
  // making it odd. The sum of two odd numbers is even.In (1) that makes
  // c^2 even and therefore c even. (4) The sum of 3 even numbers is even and 
  // P must then be even.
  //
  // If only a or b is even and the other odd
  // by (3) and (4) the sum of an odd and even number c^2 must be odd and there
  // for c must be odd. The sum of two odd numbers and one even number is even
  // and P must then be even.
  //
  // We can therefor conclude that we only need to look for even values of p.

  int p, a, b, c, solutions, highest = 0, result = 0;

  // p = 6 because it's the smallest p for which three integral sides of
  // a triangle can be found, e.g. 1,2,3 or 2,2,2.
  for (p = 6; p <= 1000; p += 2) {
    solutions = 0;

    for (a = 1; a + 2 < p; a++) {
      b = (pow(p, 2) - 2 * p * a) / (2 * (p - a));
      c = p - a - b;

      if (b < 0 || c < 0)
        continue;
      if (c == b)
        break;

      if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        /*printf("p: %d, {%d, %d, %d}\n", p, a, b, c); */
        solutions++;
      }
    }

    if (solutions > highest) {
      highest = solutions;
      result = p;
    }
  }

  printf("Answer: %d, solutions: %d\n", result, highest);

  return 0;
}
