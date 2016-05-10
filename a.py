from math import *

t = int(raw_input())
for x in range(t):
    ans = 0
    a,b = map(int, raw_input().split())
    c = b/2
    d = ceil(b/2)
    q = floor(c/2)
    if d%2 == 0:
        i = 0
        while i < q:
            if (c-i)%2 == 0:
                g = (factorial(((c-i)/2) + i)/ (factorial(i) * factorial((c-i)/2)))
                ans = ans + pow(g,2)
            i = i + 1
    else:
        i = 0
        while i <= q:
            if (c-i)%2 == 0:
                g = (factorial(((c-i)/2) + i)/ (factorial(i) * factorial((c-i)/2)))
                ans = ans + pow(g,2)
            i = i + 1
    print((a, ans))



