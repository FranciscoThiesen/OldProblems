import math

a = float(input())
b = float(input())
c = float(input())
x = math.ceil(a/c) * math.ceil(b/c)
y = int(x)
print(y)