def doit():
	s = input()
	freq = [0] * 26
	for x in s:
		freq[ord(x) - ord('a')] = freq[ord(x) - ord('a')] + 1
	resp = 0
	sz = len(s)
	for x in s:
		inc = float(freq[ord(x) - ord('a')]) / sz
		resp = resp + inc
	print("%.10f" % resp)
doit()
