x = input()
i = 0
words = []
while(i < x):
	word = raw_input()
	if(len(word) > 10):
		word1 = word[0]
		word1 = word1 + str(len(word) - 2)
		word1 = word1 + word[len(word) - 1]
		words.append(word1)
		i = i + 1
	else:
		words.append(word)
		i = i + 1
for x in words:
	print(x)
