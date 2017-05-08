n = int(raw_input())
a = list(map(int, raw_input().split()))

ans = 0
maxTot = 0
tmp = 0
minu = 0

for x in range(n):
	minu = 0
	tmp = 0
	for k in range(x, n, 1):
		if a[k] <= minu:
			tmp = tmp + 1
		minu = minu + 1
	for j in range(0, x, 1):
		if a[j] <= minu:
			tmp = tmp + 1
		minu = minu + 1
	if tmp > maxTot:
		maxTot = tmp
		ans = x
		print(maxTot)
		print(x)
print(a)
print(ans + 1)
	

