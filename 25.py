fib = [1, 1]

i = 1
while True:
    fib.append(fib[i - 1] + fib[i])
    i += 1
    if len(str(fib[i])) == 1000:
        print i + 1
        break
