
count = 0
seqs = {}

for i in range(1,1000000):
    tmp = i
    seq = [i]
    while True:
        if tmp % 2 == 0:
            tmp /= 2
        else:
            tmp = 3 * tmp + 1            
        if tmp in seqs:
            seqs[i] = seq + seqs[tmp]
            break
        elif tmp == 1:
            seqs[i] = seq + [1]
            break
        else:
            seq.append(tmp)

number = 0
length = 0
for i in seqs:
    l = len(seqs[i])
    if l > length:
        length = l
        number = i

print number, length

