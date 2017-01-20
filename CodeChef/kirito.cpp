#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define max_value 10000000
vector<bool> prime(3163, true);
vector<int> primu;

void sieve()
{
	prime[0] = prime[1] = false;
	for(ll i = 2; i * i <= max_value; ++i)
	{
		if(prime[(int)i])
		{
            primu.pb(i);
			for(ll j = i*i; j <= max_value; j+=i)
			{
				prime[(int)j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	sieve();
	int t;
	cin >> t;
    unordered_map<int, int> magic;
    while(t--)
    {
		int n;
		cin >> n;
		int ans = 0;
        	vector<int> p;
        	int x;
		for(int i = 0; i < n; ++i)
		{
			cin >> x;
        		    int max_div = ceil(sqrt(x));
          		  int mx = 0;
			for(auto primu_atual : primu)
			{
				if(x % primu[i] == 0)
				{
					p.pb(primu[i]);
					if(magic.find(primu[i]) == magic.end())
						magic[primu[i]] = 0;
					else
						mx = max(magic[primu[i]], mx);
				}
                else if (primu_atual > max_div)
                {
                    break;
                }
			}
            if (p.empty()) {
                // x is prime!
                p.pb(x);
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
