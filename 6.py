def sumpow(n):
    """Sum of numbers from 1 to n"""
    summation = 1
    for i in range(2,n + 1):
        summation += i
    return pow(summation,2)


def powsum(n):
    """Sum the squares of numbers from 1 to n"""
    summation = 1
    for i in range(2,n + 1):
        summation += pow(i,2)
    return summation

print sumpow(100) - powsum(100)