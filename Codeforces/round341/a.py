from math import *
a = int(raw_input())
nums = map(int,raw_input().split())
nums.sort()
total = 0;
i = a-1
accum = 0
while(i >= 0):
	if(nums[i]%2 == 0):
		total = total + nums[i]
	else:
		accum = accum + nums[i]
	if(accum%2 == 0):
		total = total + accum
		accum = 0
	i = i - 1
print(total)
	
