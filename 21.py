from math import sqrt

def sum_of_divisors(n):
    """gives the sum of the divisors of n"""
    res = 1
    p = 2
    while p * p <= n and n > 1:
        if n % p == 0:
            j = p * p
            n /= p
            while n % p == 0:
                j *= p
                n /= p
            res *= j - 1
            res /= p - 1
        if p == 2:
            p = 3
        else:
            p += 2
    if n > 1:
        res *= n + 1
    return res

def sum_of_proper_divisors(n):
    """gives the sum of the proper divisors of n"""
    return sum_of_divisors(n) - n

res = 0
for i in range(2, 10000):
    j = sum_of_proper_divisors(i)
    if j > i: # since perfect numbers are excluded, i != j
        if sum_of_proper_divisors(j) == i:
            res += j + i
print res