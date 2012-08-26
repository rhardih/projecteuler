import sys
import random

def toBinary(n):
  r = []
  while (n > 0):
    r.append(n % 2)
    n = n / 2
  return r

def test(a, n):
  """
  test(a, n) -> bool Tests whether n is complex.
  
  Returns:
    - True, if n is complex.
    - False, if n is probably prime.
  """
  b = toBinary(n - 1)
  d = 1
  for i in xrange(len(b) - 1, -1, -1):
    x = d
    d = (d * d) % n
    if d == 1 and x != 1 and x != n - 1:
      return True # Complex
    if b[i] == 1:
      d = (d * a) % n
  if d != 1:
    return True # Complex
  return False # Prime

def MillerRabin(n, s = 50):
  """
    MillerRabin(n, s = 1000) -> bool Checks whether n is prime or not
    
    Returns:
      - True, if n is probably prime.
      - False, if n is complex.
  """
  for j in xrange(1, s + 1):
    a = random.randint(1, n - 1)
    if (test(a, n)):
      return False # n is complex
  return True # n is prime

result = [0, 0]
for a in range(-1000, 1000 + 1):
    for b in range(-1000, 1000 + 1):
        n = 0
        while (n**2 + a * n + b) >= 2:
            if MillerRabin(n**2 + a * n + b):
                if n > result[0]:
                    result[0] = n
                    result[1] = a * b
                    print a, b, result
            else:
                break
            n += 1
                    

            