from time import time

begin = time()

result = 0
for i in range(1, 1000):
    if i % 3 == 0 or i % 5 == 0:
        result += i
print result

end = time()

print "It took:", end - begin

begin = time()

print reduce(lambda x, y: x + y, [z for z in range(1, 1000) if z % 3 == 0 or z % 5 == 0])

end = time()

print "It took:", end - begin