famb = 0
x = int(input("x"))
y = int(input("y"))
z = int(input("z"))
i = 0
while( i < 600):
	if i >= x and i <= x + 200:
		i = i + 1
		famb = famb + 1
		continue
	if i >= y and i <= y + 200:
		i = i + 1
		famb = famb + 1
		continue
	if i >= z and i <= z + 200:
		i = i + 1
		famb = famb + 1
		continue

	print((600 - famb)* 100)