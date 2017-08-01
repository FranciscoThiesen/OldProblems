from math import *
import sys
a = 1
b = 1
while True:
    try:
        a,b = map(int, raw_input().split())
    except EOFError:
        break
    print a ^ b

