from math import *

def cmp(n1, n2):
	tol = 1e-8
	if n1 + tol > n2:
		if n2 + tol > n1:
			return 0
		return 1
	return 2

n, m = map(int, raw_input().split())
resp = 0
if n <= m:
	resp = n
else:
	c = (n - m) * 2
	delta = 1 + 4 * c
	num =( -1 + sqrt(sqrt(delta))) / 2.0
	raiz = ((-1 + sqrt(delta)) / 2.0) - 1
	if cmp(raiz, floor(raiz)) == 0:
		resp = m + 1 + int(floor(raiz))
	else:
		resp = m + 1 + int(ceil(raiz))

print(resp)