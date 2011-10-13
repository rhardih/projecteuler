#include <stdio.h>

int main(int argc, const char *argv[])
{
  short d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
  long val, sum = 0;
  for (d1 = 1; d1 <= 9; d1++) {
    for(d2 = 0; d2 <= 9; d2++) {
      if(d2 == d1) {
        continue;
      }
      for(d3 = 0; d3 <= 9; d3++) {
        if(d3 == d1 ||
            d3 == d2) {
          continue;
        }
        for(d4 = 0; d4 <= 9; d4++) {
          if(d4 == d1 ||
              d4 == d2 ||
              d4 == d3 ||
              (d2 * 100 + d3 * 10 + d4) % 2 != 0) {
            continue;
          }
          for(d5 = 0; d5 <= 9; d5++) {
            if(d5 == d1 ||
                d5 == d2 ||
                d5 == d3 ||
                d5 == d4 ||
                (d3 * 100 + d4 * 10 + d5) % 3 != 0) {
              continue;
            }
            for(d6 = 0; d6 <= 9; d6++) {
              if(d6 == d1 ||
                  d6 == d2 ||
                  d6 == d3 ||
                  d6 == d4 ||
                  d6 == d5 ||
                  (d4 * 100 + d5 * 10 + d6) % 5 != 0) {
                continue;
              }
              for(d7 = 0; d7 <= 9; d7++) {
                if(d7 == d1 ||
                    d7 == d2 ||
                    d7 == d3 ||
                    d7 == d4 ||
                    d7 == d5 ||
                    d7 == d6 ||
                    (d5 * 100 + d6 * 10 + d7) % 7 != 0) {
                  continue;
                }
                for(d8 = 0; d8 <= 9; d8++) {
                  if(d8 == d1 ||
                      d8 == d2 ||
                      d8 == d3 ||
                      d8 == d4 ||
                      d8 == d5 ||
                      d8 == d6 ||
                      d8 == d7 ||
                      (d6 * 100 + d7 * 10 + d8) % 11 != 0) {
                    continue;
                  }
                  for(d9 = 0; d9 <= 9; d9++) {
                    if(d9 == d1 ||
                        d9 == d2 ||
                        d9 == d3 ||
                        d9 == d4 ||
                        d9 == d5 ||
                        d9 == d6 ||
                        d9 == d7 ||
                        d9 == d8 ||
                        (d7 * 100 + d8 * 10 + d9) % 13 != 0) {
                      continue;
                    }
                    for(d10 = 0; d10 <= 9; d10++) {
                      if(d10 == d1 ||
                          d10 == d2 ||
                          d10 == d3 ||
                          d10 == d4 ||
                          d10 == d5 ||
                          d10 == d6 ||
                          d10 == d7 ||
                          d10 == d8 ||
                          d10 == d9 ||
                          (d8 * 100 + d9 * 10 + d10) % 17 != 0) {
                        continue;
                      }
                      val = (long) 
                            d1 * 1000000000 +
                            d2 * 100000000 +
                            d3 * 10000000 +
                            d4 * 1000000 +
                            d5 * 100000 +
                            d6 * 10000 +
                            d7 * 1000 +
                            d8 * 100 +
                            d9 * 10 +
                            d10;
                      sum += val;
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
  printf("sum: %ld\n", sum);
  return 0;
}
