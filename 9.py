i = 0
while True:
    for j in range(0, i):
        for k in range(0, j):
            if pow(k,2) + pow(j,2) == pow(i,2):
                if i + j + k == 1000:
                    print i * j * k
                    i = -1
    if i == -1:
        break
    i += 1