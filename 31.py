from time import *

start = time()

def combinations(n, denoms):
    result = 0
    
    if denoms != [] and n > 0:
        result += combinations(n, denoms[1:]) + combinations(n - denoms[0], denoms)
    
    if n == 0:
        result = 1
    
    return result

coins = [200, 100, 50, 20, 10, 5, 2, 1]

end = time()

print combinations(200, coins), "time:", end - start

def ex31b(m):
    count = 0 
    a = m
    while a >=0:
        b = a
        while b >= 0:
            c = b
            while c >= 0:
                d = c
                while d >= 0:
                    e = d
                    while e >= 0:
                        f = e
                        while f >= 0:
                            g = f
                            while g >= 0:
                                
                                count += 1
                                
                                g -= 2
                            f -= 5
                        e -= 10
                    d -=20
                c -= 50
            b -= 100
        a -= 200
    return count

start = time()

val = ex31b(200)

end = time()

print val, "time:", end - start