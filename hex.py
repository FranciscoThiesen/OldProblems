from math import *

a = int(raw_input())
a = (hex(a))
ans = ""
for x in range(len(a)):
    if a[x] >= 'a' and a[x] <= 'z' and x >= 2:
        ans = ans + chr(ord(a[x])-32)
    elif x>= 2:
        ans = ans + a[x]
print ans

