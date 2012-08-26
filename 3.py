# =================================================================
# = What is the largest prime factor of the number 600851475143 ? =
# =================================================================

from math import *

tmp = 600851475143
limit = int(sqrt(tmp))
result = []

for i in range (2, limit):
    if (tmp % i == 0):
        result.append(i)
        tmp /= i

print result