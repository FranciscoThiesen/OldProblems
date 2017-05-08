#include <unordered_map>
#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>

using namespace std;
 
#define pb push_back
#define mp make_pair
#define ll long long

vector<bool> prime(3163, true);
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
 
int main()
{
	sieve(3163);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		unordered_map<int, int> magic;
		int n;
		scanf("%d", &n);
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			vector<int> p;
			int x;
			scanf("%d", &x);
			int mx = 0;
			for(int i = 0; i < primu.size(); ++i)
			{
				if(primu[i] <= x && x%(primu[i]) == 0)
				{
					p.pb(primu[i]);
					if(magic.find(primu[i]) == magic.end())
						magic[primu[i]] = 1;
					else
						mx = max(magic[primu[i]], mx);
				}
				else if(primu[i] > x)
					break;
			}
			for(auto& q : p)
				magic[q] = mx + 1;
			if(ans < mx + 1)
				ans = mx + 1;
			p.clear();
		}
		printf("%d\n", ans);
	}
	return 0;
} 