from math import *
def run():
	x = int(input())
	y = map(int, input().split())
	z = map(int, input().split())
	i = 1
	
	while(i <= x):
		if any(i for k in y) or any(i for k in z):
			i = i + 1		
	if i == x + 1:
		print("I become the guy.")
		print (i)
	else:
		print("Oh, my keyboard!")
		print(i)

run()