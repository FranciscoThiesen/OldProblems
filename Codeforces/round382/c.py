from math import *

fib = [2, 3]
for x in range(2,140):
	fib.append(fib[x-1] + fib[x-2])

n = int(raw_input());

i = 0
while i < len(fib):
	if(n < fib[i]):
		print(i)
		break
	i = i + 1

