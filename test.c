#include <assert.h>
#include "helpers.h"


int test_recursive_factorial()
{
  assert(recursive_factorial(0) == 1);
  assert(recursive_factorial(1) == 1);
  assert(recursive_factorial(2) == 2);
  assert(recursive_factorial(3) == 6);
  assert(recursive_factorial(20) == 2432902008176640000);
  return 0;
}

int test_loopfactorial()
{
  assert(loopfactorial(0) == 1);
  assert(loopfactorial(1) == 1);
  assert(loopfactorial(2) == 2);
  assert(loopfactorial(3) == 6);
  assert(loopfactorial(20) == 2432902008176640000);
  return 0;
}

int main(int argc, const char *argv[])
{
  test_recursive_factorial();
  test_loopfactorial();
  return 0;
}
