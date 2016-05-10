from math import *

a = 1
while a != -1:
	a = str(raw_input())
	if a == "-1":
		break
	if len(a) >= 2:
		if a[1] == 'x':
			print(int(a,16))
		else:
			i = 0
			ans = str(hex(int(a)))
			resp = ""
			while i < len(ans):
				if ans[i] >= 'a' and ans[i] <= 'z' and ans[i] != 'x':
					resp += (chr(ord(ans[i])-32))
				else:
					resp +=(ans[i])
				i = i+1	
			print(resp)
	else:
		ans = str(hex(int(a)))
		resp1 = ""
		i = 0
		while i < len(ans):
			if ans[i] >= 'a' and ans[i] <= 'z' and ans[i] != 'x':
				resp1 += (chr(ord(ans[i])-32))
			else:
				resp1 +=(ans[i])
			i = i+1	
		print(resp1)
