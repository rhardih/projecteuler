from math import factorial

sum = 0
for n in range(23, 101):
  for r in range(1, n):
    if factorial(n) / (factorial(r) * factorial(n - r)) > 1000000:
      sum += 1
print sum
