from math import *

mod = (10 ** 9) + 7

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def modFact(n):
    ans=1
    if n <= mod//2:
        for i in range(1,n+1):
            ans = (ans * i) % mod   
    else:
        for i in range(n+1,mod):
            ans = (ans * i) % mod
        ans = modinv(ans, mod)
        ans = -1*ans + mod
    return ans % mod

def modmult(a, b):
	return a*b % mod

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
					for j in xrange(i+1,u):
						if i == j:
							continue
						if 2 * (radius_list[i] + radius_list[j]) > p + radius_list[i] + radius_list[j] - 1:
							continue
						else:
							tot_spaces = p + radius_list[i] + radius_list[j] - 1 - 2 * sum(radius_list)
							print(tot_spaces + u, u)
							num_possible_spaces_confs = choose(tot_spaces + u, u)
							print("Acabei o choose")
							tmp = modmult(num_possible_spaces_confs,umb)
							tmp = (tmp * 2)%mod
							ans = (ans + tmp)%mod
			f.write("Case #{}: {}\n".format(t+1,ans))
			print(ans)
		f.close()

solve()


