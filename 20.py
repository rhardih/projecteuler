result = [1]
for i in range(1,101):
    result.append(i * result[i - 1])

count = 0
for letter in str(result[len(result) - 1]):
    count += int(letter)

print count