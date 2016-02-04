#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#include <utility>
using namespace std;

int _sieve_size;
bitset<100000000> bs;
vector<int> primes;

void sieve(long upperbound)
{
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(long i = 2; i <= _sieve_size; i++)
	{
		if(bs[i])
		{
			for(long j = i*i; j < _sieve_size; j += i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}
bool isPrime(long n)
{
	if(n <= _sieve_size)
		return bs[n];
	for(int i = 0; i < (int)primes.size();i++)
		if(n%primes[i] == 0)
			return false;
	return true;
}

int main()
{
	sieve(10000000);
	int t;
	scanf("%d", &t);
	for(int x = 0; x < t; x++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for(int t = a; t <= b; t++)
		{
			if(isPrime(t))
				cout << t << endl;
		}
		cout << endl;
	}
	return 0;
}
