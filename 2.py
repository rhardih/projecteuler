# ===============================================================================================
# = Find the sum of all the even-valued terms in the sequence which do not exceed four million. =
# ===============================================================================================
arr = [1, 1]
ans = 0
i = 0

while (arr[len(arr) - 1] <= 4 * pow(10, 6)):
    i += 1
    arr.append(arr[i - 1] + arr[i])
    if (arr[i + 1] % 2 == 0):
        ans += arr[i + 1]

print ans