#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

#define pb push_back
typedef long long ll;


vector<bool> prime(100001, true);
vector<int> primu;
 
void sieve(ll n)
{
	prime[0] = prime[1] = false;
	for(ll i = 2; i*i <= n; ++i)
	{
		if(prime[(int)i])
		{
			if(i <= n)
			{
				for(ll j = i*i; j <=n; j+=i)
				{
					prime[(int)j] = false;
				}
			}
		}
	}
	for(int i = 2; i <= n; ++i)
	{
		if(prime[i])
		{
			primu.pb(i);
		}
	}
 
}

bool isPrime(ll n)
{
	if(n < 2)
		return false;
	if(n == 2 || n == 3)
		return true;
	if(n%2 == 0 || n%3 == 0)
		return false;
	int sz = primu.size();
	for(int i = 0; primu[i] <= ceil(n/2) && i < sz; ++i)
	{
		if(n%primu[i] == 0)
			return false;
	}	
	return true;
}

int main()
{
	ll n;
	sieve(100001);
	while(scanf("%lld", &n) != EOF)
	{
		if(n == 2)
			printf("1\n");
		else if(n%2 == 0)
			printf("%lld\n", n-2);
		else if(isPrime(n))
			printf("%lld\n", n-1);
		else if(isPrime(n-2))
			printf("%lld\n", n-2);
		else
			printf("%lld\n", n-3);
	}
	return 0;
}
