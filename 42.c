#include <stdio.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

int main(int argc, const char *argv[])
{
  char word[40];
  int result = 0, i, word_sum, word_len, extra, possible_square;
  while(scanf("\"%[A-Z]\",", word) != EOF) {
    // Offset by 64 to go from ascii value to alphabet position
    word_sum = 0;
    word_len = strlen(word);
    for (i = 0; i < word_len; i++) {
      word_sum += (int)word[i];
    }
    word_sum -= word_len * 64;
    extra = (int)floor(sqrt(word_sum * 2));
    possible_square = word_sum * 2 - extra;
    if (square(possible_square)) {
      result++;
      printf("%s, %d\n", word, word_sum);
    }
  }
  
  return result;
}
