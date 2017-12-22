from math import *

r, s, m, d, n = map(int, input().split())
brands = list(map(int, input().split()))
receitas = []
naoPode = dict()
for x in range(s+m+d):
	lista = list(map(int, input().split()))
	lista.pop(0)
	for k in range(len(lista)):
		lista[k] = lista[k] - 1
	receitas.append(lista)

print(receitas)

for x in range(n):
	a, b = map(int, input().split())
	if a > b:
		a,b = b,a
	naoPode[(a-1,b-1)] = 1


print(naoPode)
tot = 0
for i in range(s):
	for j in range(s, s+m):
		for k in range(s+m, s+m+d):
			if (i, j) in naoPode or (i, k) in naoPode or (k, j) in naoPode:
				continue
			tmp = 1
			temNoPrato = []
			for p in receitas[i]:
				temNoPrato.append(p)
			for p in receitas[j]:
				temNoPrato.append(p)
			for p in receitas[k]:
				temNoPrato.append(p)
			temNoPrato = set(temNoPrato)

			for item in temNoPrato:
				tmp = tmp * brands[item]
			tot += tmp
			
limit = 10 ** 18
print("{}".format(tot))
if tot > limit:
	print("too many")
else:
	print(tot)
