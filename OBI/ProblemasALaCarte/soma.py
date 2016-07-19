from math import *
a, b = map(int, raw_input().split())
avg = (a+b)/2.0
print int(avg* (abs(a-b)+1))

