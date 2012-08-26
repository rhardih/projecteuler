#include "38.h"
#include "problems.h"

#include "helpers.h"

char *desc38()
{
  return "Take the number 192 and multiply it by each of 1, 2, and 3:\n\n"
  "192  1 = 192\n"
  "192  2 = 384\n"
  "192  3 = 576\n\n"
  "By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)\n\n"
  "The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).\n\n"
  "What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?";
}

int run38(char *output)
{
  char tmp[1000] = "";
  
  /*
   9abc * 2 = xxxxx
   
   # Must be lower than 95bc since 95bc * 2 >= 190xx
   
   9[1-4]bc * 2 = 18[2,4,6,8]xx
   
   # 94bc can't work since 8 is double in xxxxx
   
   9[1-3]bc * 2 = 18[2,4,6]xx
   
   # 91bc can't work since 1 is in both numbers, thus it must be
   
   9[2-3]bc * 2 = 18[4, 6]xx
   
   # if 92 is chosen we are left with 3 5 6 7, 
   # where it is not possible to construct any two numbers x and y,
   # such that x * 2 = y, therefor it must be 93 which leaves 2 4 5 7.
   # It can be seen then that x = 27 and y = 54, makes 27 * 2 = 54, which is correct.
   # The solution must then be:
   
   932718654
   */
  
  /* Since the given example lists 918272645 as a concatenated product, we 
   * assume that this is a lower bound, hence we look in the range 
   * 9xxxxxxxx and the number should be of one of the forms:
   * 9x xxx xxxx, 9xx xxx xxx or 9xxx xxxxx */
  int a = 9, b, c, d, e, f, g, h, i;
	
  int result = 0, num;
  int xx, xxx, xxxx;
  int aaa, bbb, ccc;
  int zzzz, zzzzz;
	
	for(b = 1; b < 9; b ++) { // b can't be 9 since a is 9
		for(c = 1; c <= 9; c++) {
			if( c == a ||
         c == b) continue;
			for(d = 1; d <= 9; d++) {
				if( d == a ||
           d == b ||
           d == c) continue;
				for(e = 1; e <= 9; e++) {
					if( e == a ||
             e == b ||
             e == c ||
             e == d) continue;
					for(f = 1; f <= 9; f++) {
						if( f == a ||
               f == b ||
               f == c ||
               f == d ||
               f == e) continue;
						for(g = 1; g <= 9; g++) {
							if( g == a ||
                 g == b ||
                 g == c ||
                 g == d ||
                 g == e ||
                 g == f) continue;
							for(h = 1; h <= 9; h++) {
								if( h == a ||
                   h == b ||
                   h == c ||
                   h == d ||
                   h == e ||
                   h == f ||
                   h == g) continue;
								for(i = 1; i <= 9; i++) {
									if( i == a ||
                     i == b ||
                     i == c ||
                     i == d ||
                     i == e ||
                     i == f ||
                     i == g ||
                     i == h) continue;
                  
                  xx = a * 10 + b;
                  xxx = (c * 100) + (d * 10) + e;
                  xxxx = (f * 1000) + (g * 100) + (h * 10) + i;
                  if (xx * 2 == xxx && xx * 3 == xxxx) {
                    num = (xx * 10000000) + (xxx * 10000) + xxxx;
                    if (num > result) {
                      result = num;
                      sprintf(tmp, "%sxx: %i, xxx: %i, xxxx: %i - %i\n", output, xx, xxx, xxxx, result);
                      sprintf(output, "%s", tmp);
                    }
                  }
                  
                  aaa = (a * 100) + (b * 10) + c;
                  bbb = (d * 100) + (e * 10) + f;
                  ccc = (g * 100) + (h * 10) + i;
                  if (aaa * 2 == bbb && aaa * 3 == ccc) {
                    num = (aaa * 1000000) + (bbb * 1000) + ccc;
                    if (num > result) {
                      result = num;
                      sprintf(tmp, "%s aaa: %i, bbb: %i, ccc: %i - %i\n", output, aaa, bbb, ccc, result);
                      sprintf(output, "%s", tmp);
                    }
                  }
                  
                  zzzz = (a * 1000) + (b * 100) + (c * 10) + d;
                  zzzzz = (e * 10000) + (f * 1000) + (g * 100) + (h * 10) + i;
                  if (zzzz * 2 == zzzzz) {
                    num = zzzz * 100000 + zzzzz;
                    if (num > result) {
                      result = num;
                      sprintf(tmp, "%szzzz: %i, zzzzz: %i - %i\n", output, zzzz, zzzzz, result);
                      sprintf(output, "%s", tmp);
                    }
                  }
								}
							}
						}
					}
				}
			}
		}
	}
  
  return result;
}