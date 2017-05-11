from math import *

n = int(raw_input())
pos = list(map(float, raw_input().split()))
sp = list(map(float, raw_input().split()))

mx = max(pos)
mn = min(pos)

def f(p):
	ans = 0.0
	for x in xrange(n):
		ans = max(ans, abs(pos[x] - p)/sp[x])
	return ans

def bin():
	hi = mx
	lo = mn
	best = 10000000000.0
	for x in xrange(300):
		mid =(hi + lo)/2.0
		k = f(lo)
		q = f(hi)
		if(k < q):
			hi = mid
			best = min(best, k)
		else:
			lo = mid
			best = min(best, q)
	return best

print '%.8f' % bin()



