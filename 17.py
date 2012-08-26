# integer number to english word conversion
# can be used for numbers as large as 999 vigintillion 
# (a vigintillion is 10 to the power 60)
# tested with Python25 and Python30  by  vegaseat  03dec2008

def int2word(n):
    """
    takes an integer number n and converts it into 
    a string of english words, returns the string
    """
    if n == 0:
        return "zero "
    # make sure n is a positive integer
    n = int(abs(n))

    # break the number into groups of 3 digits using slicing
    # each group representing hundred, thousand, million, billion, ...
    n3_list = []
    # create numeric string
    ns = str(n)
    for k in range(3, 66, 3):
        r = ns[-k:]
        q = len(ns) - k
        # break if end of ns has been reached
        if q < -2:
            break
        else:
            if  q >= 0:
                n3_list.append(int(r[:3]))
            elif q >= -1:
                n3_list.append(int(r[:2]))
            elif q >= -2:
                n3_list.append(int(r[:1]))

    # the lists of number words ...
    ones_list = ["", "one ","two ","three ","four ", "five ",
        "six ","seven ","eight ","nine "]

    tens_list = ["ten ","eleven ","twelve ","thirteen ", "fourteen ",
        "fifteen ","sixteen ","seventeen ","eighteen ","nineteen "]

    twenties_list = ["","","twenty ","thirty ","forty ",
        "fifty ","sixty ","seventy ","eighty ","ninety "]

    thousands_list = ["","thousand ","million ", "billion ", 
        "trillion ", "quadrillion ", "quintillion ", "sextillion ", 
        "septillion ", "octillion ", "nonillion ", "decillion ", 
        "undecillion ", "duodecillion ", "tredecillion ", 
        "quattuordecillion ", "sexdecillion ", "septendecillion ", 
        "octodecillion ", "novemdecillion ", "vigintillion "]
        
    # form a string of words
    n2w = ""
    for i, x in enumerate(n3_list):
        # break each group of 3 digits into
        # ones_list, tens_list/twenties_list, hundreds
        hun = x % 10
        ten = (x % 100)//10
        one = (x % 1000)//100
        if x == 0:
            continue  # skip
        else:
            t = thousands_list[i]
        if ten == 0:
            if x > 100 and x % 100 != 0:
                n2w = "and " + ones_list[hun] + t + n2w
            else:
                n2w = ones_list[hun] + t + n2w
        elif ten == 1:
            if x > 100 and x % 100 != 0:
                n2w = "and " + tens_list[hun] + t + n2w
            else:
                n2w = tens_list[hun] + t + n2w
        elif ten > 1:
            if x > 100 and x % 100 != 0:
                n2w = "and " + twenties_list[ten] + ones_list[hun] + t + n2w
            else:
                n2w = twenties_list[ten] + ones_list[hun] + t + n2w
        if one > 0:
            n2w = ones_list[one] + "hundred " + n2w
    return n2w


# testing ...
if __name__ == '__main__':
    
    count = 0
    for i in range(1,1001):
        if i > 100 and i % 100 != 0:
            print len(int2word(i).replace(" ", "")), int2word(i)
            count += len(int2word(i).replace(" ", ""))
        else:
            print len(int2word(i).replace(" ", "")), int2word(i)
            count += len(int2word(i).replace(" ", ""))
    print count