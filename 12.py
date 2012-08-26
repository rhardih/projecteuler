# triangle number:
# t(n) = n^2 + n / 2

from math import sqrt

def tnum(n):
    return (n * n + n) / 2

index = 1
while True:
    t = tnum(index)
    c = 0
    
    for i in range(1, int(sqrt(t))):
        if t % i == 0:
            c += 2
        
    if c > 500:
        print "index:", index, "t:", t, "c:", c
        break
    index += 1