from math import *

mod = (10 ** 9) + 7

def egcd(aa, bb):
    lastremainder, remainder = abs(aa), abs(bb)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if aa < 0 else 1), lasty * (-1 if bb < 0 else 1)
 
def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def modFact(n):
    ans=1
    for i in range(1,n+1):
        ans = ans * i % mod  
    return ans % mod

def choose(n, k):
    num = 1
    if n < 0:
    	return 0
    for i in range(n - k + 1, n + 1):
        num = (num * i) % mod
    d = modFact(k)
    return (num * modinv(d, mod)) % mod


def solve():
	tests = int(raw_input())
	with open('out.txt', 'w') as f:
		for t in xrange(tests):
			u, p = map(int, raw_input().split())
			possible_orders = modFact(u)
			radius_sum = 0
			ans = 0
			radius_list = []
			for x in xrange(u):
				r = int(raw_input())
				radius_sum = radius_sum + r
				radius_list.append(r)
			
			pos = True
			if u == 1:
				ans = p
				pos = False
			if pos:
				umb = modFact(u - 2)
				for i in xrange(u):
					for j in xrange(i+1, u):
						if 2 * (radius_list[i] + radius_list[j]) > p + radius_list[i] + radius_list[j] - 1:
							continue
						else:
							tot_spaces = p + radius_list[i] + radius_list[j] - 1 - 2 * sum(radius_list)
							#print(i, j)
							num_possible_spaces_confs = choose(tot_spaces + u, u)
							#print("acabei o choose")
							tmp = (num_possible_spaces_confs * umb * 2)%mod
							ans = (ans + tmp)%mod
			f.write("Case #{}: {}\n".format(t+1,ans))

		f.close()

solve()


