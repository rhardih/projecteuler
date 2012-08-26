from math import *

n = 3
fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]

result = 0

while True:
        
    num = str(n)
    _sum = 0
    for d in num:
        _sum += fact[int(d)]
        
    if n == _sum:
        result += n
    
    if n > len(num) * fact[9]:
        break
    
    n += 1

print result