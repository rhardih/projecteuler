# sum_of_fifth_powers_of_digits
def sofpod(n):
    s = str(n)
    result = []
    for i in range(len(s)):
        result.append(int(s[i]))
    result = [x**5 for x in result]
    return sum(result)


result = 0
i = 2
while True:
    if i > int(len(str(i))) * 9**5:
        break
    j = sofpod(i)
    if i == j:
        result += i
    i += 1

print "result:", result