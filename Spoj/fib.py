from math import *

a = [1]
i = 1
while(i <= 100):
	a.append(a[i-1] * i)
	#print a[i]
	i = i + 1
x = input()
r = 0
while r < x:
	q = input()
	print(a[q])
	r = r + 1

