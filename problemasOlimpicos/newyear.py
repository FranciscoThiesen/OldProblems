from math import *

def new_year():
	x = int(raw_input())
	y = int(raw_input())
	i = 1
	p = 0
	while i <= x:
		k = int(raw_input())
		if k + i == y:
			p = p + 1
			break
		i = i + 1

	if p >= 1:
		print("YES")
	else:
		print("NO")

new_year()