from math import *

n = int(raw_input())

k = {}
for x in range(n):
	a, b, c, d = map(str, raw_input().split())
	k.update({a:(b,c,d)})

while True:
	try:
	 	a, b = map(str, raw_input().split())
	except:
		break
	if b in list(k[a]):
		print("Uhul! Seu amigo secreto vai adorar o/")
	else:
		print("Tente Novamente!")
