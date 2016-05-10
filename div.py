from math import *

a, b = map(int, raw_input().split())
x = int(floor(a/b))
y = a - (x*b)
print("%d %d" % (x,y))
