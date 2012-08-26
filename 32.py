from itertools import permutations

def list_to_num(l):
    num = ""
    for i in l:
        num += i
    return int(num)

result = []
for p in permutations("123456789", 9):
    #    1-9         1234567-9876543                                         1-9
    # if int(i[0]) * int(i[1] + i[2] + i[3] + i[4] + i[5] + i[6] + i[7] ) == int(i[8]):
    #     result += 1
    
    # shows that we can exclude any identity with a one-digit multiplicand and one-digit product
    
    #     1-9        123456-987654                                   12-98
    # if int(i[0]) * int(i[1] + i[2] + i[3] + i[4] + i[5] + i[6]) == int(i[7] + i[8]):
    #     result += 1
    
    # shows that we can exclude any identity with a one-digit multiplicand and two-digit product
    
    #    1-9         12345-98765                              123-987
    # if int(i[0]) * int(i[1] + i[2] + i[3] + i[4] + i[5]) == int(i[6] + i[7] + i[8]):
    #     result += 1
    
    # shows that we can exclude any identity with a one-digit multiplicand and three-digit product
    
    # 1-9         1234-9876                              1234-9876
    # if int(i[0]) * int(i[1] + i[2] + i[3] + i[4]) == int(i[5] + i[6] + i[7] + i[8]):
    #     print i[0], "x", int(i[1] + i[2] + i[3] + i[4]), "=", int(i[5] + i[6] + i[7] + i[8])
    #     result += int(i[5] + i[6] + i[7] + i[8])
    
    # here we have overlapping results, calculate away
    
    for i in range(1, 9):
        for j in range(i + 1, 9):
            multiplicand = list_to_num(p[0:i])
            multiplier = list_to_num(p[i:j])
            product = list_to_num(p[j:])
            if multiplicand * multiplier == product:
                print multiplicand, "x", multiplier, "=", product
                result.append(product)

print sum(set(result))



