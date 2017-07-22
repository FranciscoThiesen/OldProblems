from math import *
from fractions import *

parent = []
rank = []
edges = []# tam, num, denom, s, t
n = 0

def find(x):
	if parent[x] != x:
		parent[x] = find(parent[x])
	return parent[x]

def unite(x, y):
	if find(x) != find(y):
		if rank[x] > rank[y]:
			parent[y] = x
		else:
			parent[x] = y
		if rank[x] == rank[y]:
			rank[x] = rank[x] + 1

def kruskal(k):
	for x in edges:
		x[0] = x[1] - k*x[2]

	for x in xrange(n):
		parent[x] = x
		rank[x] = 0

	edges.sort(reverse=True)

	sumDenom = 0, sumNum = 0, resp = 0

	for e in edges:
		if find(e[3]) != find(e[4]):
			unite(e[3], e[4])
			sumNum = sumNum + e[1]
			sumDenom = sumDenom + e[2]
			resp = resp + e[0]

	return (resp, sumNum, sumDenom)

def reduce(i, j):
	div = gcd(i, j)
	if div == 1:
		return (i, j)
	return (i/div, j/div)

def binSearch():
	lo = 0, hi = 1e7
	a = 0, b = 0, c = 0
	while hi - lo > 1e-8:
		mid = lo + (hi-lo)/2.0
		a, b, c = kruskal(mid)
		if a < 0:
			hi = mid
		else:
			lo = mid
	out = reduce(b, c)
	print("{}/{}.".format(out[0], out[1]))


n, m = map(int, raw_input().split())
for x in xrange(m):
	x,y,z,w = map(int, raw_input().split())
	edges.append(float(x)/y, z, w, x, y)
	binSearch()

