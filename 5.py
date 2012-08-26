
result = 1
count = 1

for i in range(1,1000):
    while (count % i != 0) or (count % result != 0):
        count += result
    result = count

print result