n = int(raw_input())
a = map(int, raw_input().split())
a.sort()
resp = 0
mod = 10 ** 9 + 7

for x in xrange(n):
	resp = (resp + (a[x] * (pow(2,x,mod) - pow(2,n-x-1,mod))%mod))%mod

print(resp%mod)	
