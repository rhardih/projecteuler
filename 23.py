from math import *

def divisors(n):
    """finds the divisors of n"""
    result = []
    for i in range(1, int(sqrt(n) + 1)):
        if n % i == 0:
            result.append(i)
            if n / i != i:
                result.append(n / i)
    result.sort()
    return result


def proper_divisors(n):
    """finds the proper divisors of n"""
    result = divisors(n)
    return result[:len(result) - 1]

def classify_number(n):
    """determines if a number is deficient, perfect or abundant"""
    _sum = sum(proper_divisors(n))
    if _sum < n:
        return -1
    elif _sum == n:
        return 0
    else:
        return 1

def find_abundant_numbers(n):
    """finds abundant numbers with value less that or equal to n"""
    result = []
    for i in range(12, n + 1): # twelve is the smallest abundant number
        if classify_number(i) == 1:
            result.append(i)
    return result

# ===========================================================================================================
# = The real part, finding out the sum of all positive integers, that are not a sum of two abundant numbers =
# ===========================================================================================================

an = find_abundant_numbers(28123)
 
sums = set([x + y for x in an for y in an if x <= y and x + y <= 28123])

ints = set(range(28123 + 1))

print sum(ints - sums)