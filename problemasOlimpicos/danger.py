x = raw_input()
seq = 1
i = 1
a = 0
while(i < len(x)):
	if(x[i] == x[i - 1]):
		seq = seq + 1
		i = i + 1
		if(seq == 7):
			a = a + 1
	else:
		seq = 1
		i = i + 1

if(a > 0):
	print("YES")
else:
	print("NO")