result = []

for i in range(2, 100 + 1):
    for j in range(2, 100 + 1):
        result.append(i**j)

result = list(set(result))

print len(result)
