#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "23.h"

int main()
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
    
    printf("result: %d\n", result);
    
    free(an);
    
    printf("sod(28): %d\n", sum_of_proper_divisors(28));
    
    
    return 0;
}

// finds abundant numbers with value <= n
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

int array_sum(int len, int arr[])
{
    int result = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        result += arr[i];
    }
    return result;
}

// finds divisors of n. remember to free *result
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