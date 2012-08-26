#include "41.h"
#include "problems.h"

#include "helpers.h"

char *desc41()
{
  return "We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.\n\n"
  "What is the largest n-digit pandigital prime that exists?";
}

int run41(char *output)
{
  // Assuming n <= 9
  int result = 0, i;
	for(i = 987654321; i > 0; i--) {
    if (pandigital(i) && prime(i)) {
      result = i;
      break;
    }
  }
  return result;
}