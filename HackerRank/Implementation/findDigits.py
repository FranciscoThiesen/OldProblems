from math import *

i = int(raw_input())
j = 0
while(j < i):
    total = 0
    num1 = int(input())
    num = str(num1)
    q = map(int,num)
    for x in q:
        if x != 0 and num1%x == 0:
            total = total + 1
    print(total)
    j = j + 1


