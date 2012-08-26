import re

names_raw = open("names.txt", 'r').read()
names_arr = re.compile('(")').sub("", names_raw).split(",")
names_arr.sort()

count = 0
for i in range(len(names_arr)):
    name_value = 0
    for j in names_arr[i]:
        name_value += ord(j) - 64 # ASCII offset
    count += name_value * (i + 1) # zero indexed
print count
