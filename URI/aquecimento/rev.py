from math import *

pos = [0,0,36,360]

def dig(n):
    if(n%2 == 0):
        return 36 * pow(10, n-2) + 45*pow(10,n-4)*9
    else:
        return 36 * pow(10, n-2) + 45*pow(10,n-4)*11

i = 4
a = int(raw_input())
print (int((dig(a))))
