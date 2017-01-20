#include <bits/stdc++.h>
 
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
	ios::sync_with_stdio(0);
	sieve(3162);
	int t;
	cin >> t;
	while(t--)
	{
		unordered_map<int, int> magic;
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			vector<int> p;
			int x;
			cin >> x;	
			int mx = 0;
			for(int i = 0; i < primu.size(); ++i)
			{
				if(primu[i] <= x && x%(primu[i]) == 0)
				{
					p.pb(primu[i]);
					if(magic.find(primu[i]) == magic.end())
						magic[primu[i]] = 0;
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
		cout << ans << endl;
		magic.clear();
	}
	return 0;
} 