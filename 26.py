from decimal import *

pre = 10000

getcontext().prec = pre

length = 0
result = 0
string = ""


for d in range(2, 1000 + 1):
    num = str(1 / Decimal(d))

    if len(num) >= pre:
        if d <= 10:
            frac = num[2:pre]
        elif d > 10 and d <= 100:
            frac = num[3:pre]
        else:
            frac = num[4:pre]
        for j in range(1, len(frac) / 2):
            if frac[0:j] == frac[j:2 * j]:
                # print frac[0:j], frac[j:2 * j]
                # print len(frac[0:j])
                if len(frac[0:j]) > length:
                    length = len(frac[0:j])
                    result = d
                    string = frac[0:j]
                break

print length, result, string