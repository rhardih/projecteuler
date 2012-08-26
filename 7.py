# ========================
# = Finds the n'th prime =
# ========================

from math import *

primes = [2] # pre-fill the first prime
i = 3 # start point

while True:
    isPrime = True
    for j in range(0, len(primes)):        
        if i % primes[j] == 0:
            isPrime = False
        # no need to look further than sqrt(i) 
        # since n^2 = i, would mean i % n = 0
        if primes[j] > sqrt(i):
            if isPrime:
                primes.append(i)
            break
    i += 1
    
    if len(primes) >= 10001:
        print primes[len(primes) - 1]
        break
