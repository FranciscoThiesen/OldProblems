from math import *
import sys
def isPrime(n):
	if(n < 2):
		return False
	if(n == 2 or n == 3):
		return True
	if(n%2 == 0 or n%3 == 0):
		return False
	i = 5
	while i * i <= n:
		if n%i == 0 or n%(i+2) == 0:
			return False
		i = i + 6
	return True

try:
	while True:
		n = int(raw_input())
		if n == 2:
			print(1)
		elif n%2 == 0:
			print(n-2)
		elif isPrime(n):
			print(n-1)
		elif isPrime(n-2):
			print(n-2)
		else:
			print(n-3)
except EOFError:
	pass