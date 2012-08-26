# =============================================================================
# = Find the largest palindrome made from the product of two 3-digit numbers. =
# =============================================================================

def reverse(arr):
    result = []
    for i in range(1, len(arr) + 1):
        result.append(arr[-i])
    return result

def pnd(num):
    steps = [10]
    for i in range(0, len(str(num))):
        steps.append(steps[i] * 10)
    
    digits = [num % 10]
    for i in range(0, len(steps) - 2): # -1 for index, -1 for an existing element
        digits.append(((num - digits[i]) % (steps[i] * 10)) / steps[i])

    return digits == reverse(digits)

result = 0
i = 0
j = 0
for i in range(900, 1000):
    for j in range(900, 1000):
        if pnd(i * j) and i * j > result:
            result = i * j

print "Result :", i, "*", j, "=", result

            