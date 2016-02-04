from math import *

m, n= map(int, raw_input().split())
i = 0
j = []
while(i < m):
	num1= map(int, raw_input().split())
	a = 1
	while(a < len(num1)):
		j.append(num1[a])
		a = a + 1
	i = i + 1

set = set(j)
if len(set) == n:
	print("YES")
else:
	print("NO") 