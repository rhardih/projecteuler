result = 1

# corner_values
cv = [0, 0, 0, 1]

for i in range(1, 1001 / 2 + 1):
    j = 2 * i
    cv[0] = cv[3] + j
    cv[1] = cv[0] + j
    cv[2] = cv[1] + j
    cv[3] = cv[2] + j
    result += sum(cv)

print result