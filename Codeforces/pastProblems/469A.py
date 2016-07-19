from math import *
num0 = int(raw_input())
num1= map(int, raw_input().split())
num2= map(int, raw_input().split())
arr = []
for q in range(num0):
    arr.append(0)
final = list(num1 + num2)
# final = list(final)
size = 0
for x in final:
    if x != 0:
        arr[x-1] = 1
flag = True
for y in range(num0):
    if arr[y] == 0:
        flag = False


if flag == True:
	print("I become the guy.")
else:
	print("Oh, my keyboard!")
