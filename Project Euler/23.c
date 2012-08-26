#include "23.h"
#include "problems.h"

char *desc23()
{
  return "A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.\n\n"
  "A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.\n\n"
  "As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.\n\n"
  "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.";
}

int run23(char *output)
{
  // abundant numbers
  int *an;
  int i, j, count, result;
  
  count = abundant_numbers(28123, &an);
  
  int ints[28123];
  for(i = 0; i < 28123; i++)
  {
    ints[i] = i + 1;
  }
  
  int ab_sums[28123];
  for(i = 0; i < 28123; i++)
  {
    ab_sums[i] = 0;
  }
  
  for(i = 0; i < count; i++)
  {
    for(j = i; j < count; j++)
    {
      if(an[i] + an[j] < 28123)
      {
        ab_sums[an[i] + an[j]] = 1;
      }
    }
  }
  
  result = 0;
  
  for(i = 0; i < 28123; i++)
  {
    if(!ab_sums[i])
    {
      result += i;
    }
  }
  
  sprintf(output, "sod(28): %d\n", sum_of_proper_divisors(28));
  
  free(an);
  
  return result;
}

/* Finds all abundant numbers with value <= n.
 *
 * WIKI: In number theory, an abundant number or excessive number is a number n
 * for which the sum of divisors σ(n)>2n, or, equivalently, the sum of proper
 * divisors (or aliquot sum) s(n)>n. */
int abundant_numbers(int n, int **result)
{
  *result = malloc(n * sizeof(int));
  (*result)[0] = 12; // 12 is smallest abundant number
  // result index
  int ri = 1;
  int i;
  for(i = 14; i < n; i++) // since 13 is prime
  {
    if(classify_number(i) == 1)
    {
      (*result)[ri++] = i;
    }
  }
  *result = realloc(*result, ri * sizeof(int));
  return ri;
}

// 1:   abundant
// 0:   perfect
// -1:  deficient
int classify_number(int n)
{
  // int *divs;
  // int proper_count = divisors(n, &divs) - 1;
  // int sum = array_sum(proper_count, divs);
  int sum = sum_of_proper_divisors(n);
  if(sum > n) {return 1;}
  else if(sum == n) {return 0;}
  else return -1;
}

/* Finds divisors of n. Remember to free *result.
 *
 * WIKI: In mathematics, a divisor of an integer n, also called a factor of n,
 * is an integer which divides n without leaving a remainder. */
int divisors(int n, int **result)
{
  int limit = sqrt(n) + 1;
  *result = malloc(2 * limit * sizeof(int)); // upper limit of the for loop below
  
  int result_index = 0;
  int i, temp;
  for(i = 1; i < limit; i++)
  {
    if(n % i == 0)
    {
      (*result)[result_index++] = i;
      temp = n / i;
      if(temp != i)
      {
        (*result)[result_index++] = temp;
      }
      
    }
    
  }
  
  *result = realloc(*result, result_index * sizeof(int));
  qsort(*result, result_index, sizeof(int), compare_ints);
  
  return result_index;
}

int compare_ints(const void* a, const void* b)
{
  int* arg1 = (int*) a;
  int* arg2 = (int*) b;
  if(*arg1 < *arg2) { return -1; }
  else if(*arg1 == *arg2) { return 0; }
  else return 1;
}

int sum_of_divisors(int n)
{
  int sum = 1; 
  int p = 2;
  int j;
  while (p * p <= n && n > 1) 
  {
    if(n % p == 0)
    {
      j = p * p; 
      n = n / p;
      while (n % p == 0)
      {
        j = j * p;
        n = n / p;
      }
      
      sum = sum * (j - 1);
      sum = sum / (p - 1);
    }
    
    if(p == 2)
    {
      p = 3;
    }
    else
    {
      p += 2;
    }
  }
  
  if(n > 1)
  {
    sum = sum * (n + 1);
  }
  
  return sum;
}

int sum_of_proper_divisors(int n)
{
  return sum_of_divisors(n) - n;
}