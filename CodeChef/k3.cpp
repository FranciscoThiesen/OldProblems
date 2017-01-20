#include <bits/stdc++.h>
#include <cstring>

using namespace std;
 
#define gcd __gcd
#define ll long long
#define pb push_back

vector<bool> prime(3164, true);
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

vector<int> primeFactors(int n)
{
	vector<int> ans;
	if(n == 1)
		return ans;
    while (n%2 == 0)
    {
        if(ans.empty() || ans.back() != 2);
        	ans.push_back(2);
        n = n/2;
    }
 	int sz = primu.size();
    for (int i = 0; i <= sz; ++i)
    {
    	if(primu[i] * primu[i] > n)
    		break;
        while (n%primu[i] == 0)
        {
            if(ans.empty() || ans.back() != primu[i])
            	ans.push_back(primu[i]);
            n = n/primu[i];
        }
    }
    if (n > 2)
    	ans.push_back(n);
    return ans;
}

int main()
{
	sieve(3163);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 1;
		unordered_map<int, int> primeSize;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			int longestSize = 0;
			if(n != 1)
			{
				vector<int> primeFact = primeFactors(x);
				for(auto& p : primeFact)
				{
					if(primeSize.find(p) != primeSize.end())
						longestSize = ((primeSize[p] > longestSize)? primeSize[p] : longestSize);
				}
				for(auto& p : primeFact)
					primeSize[p] = longestSize + 1;
				ans = ((longestSize+1 > ans)? longestSize + 1 : ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
 