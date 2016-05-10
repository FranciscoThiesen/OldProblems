from math import *
b = int(raw_input()) 
valores = list(int(a) for a in raw_input().split())
maiorSeq = 1
atualSeq = 1
i = 0
while i < b:
	if valores[i] == valores[i-1]:
		atualSeq = atualSeq + 1
	else:
		atualSeq = 1
	if atualSeq > maiorSeq:
		maiorSeq = atualSeq
	i = i + 1
print(maiorSeq)


