n = int(raw_input())

def euclidExtended(b, n):
    x0, x1, y0, y1 = 1, 0, 0, 1
    while n != 0:
        q, b, n = b // n, n, b % n
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return  b, x0, y0
def solveLinearModularEquation(a, b, n):
  d, xx, yy = euclidExtended(a, n)
  if (b % d == 0):
    x0 = (xx * (b / d)) % n
    for i in xrange(0, d):
      return (x0 + i * (n / d)) % n,
  else:
    return -1
i = 1
cur = 2
while i <= n:
	x = solveLinearModularEquation(i+1, i, 1)
	print(x)
	sqr = ((i+1)*x)*((i+1)*x)
	print((sqr-cur)/i)
	cur = (i+1)*x
	i = i + 1

	
	