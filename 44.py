from time import time

start = time()

result = 0
for i in range(1, 1000 + 1):
        result += i**i
print str(result)[-10:], time() - start

start = time()

print str(reduce(lambda x, y: x + y**y, range(1, 1000 + 1)))[-10:], time() - start

    