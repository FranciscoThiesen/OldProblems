#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<bool> prime(1000001, true);
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
	sieve(1000000);
	int sz = primu.size();
	vector<unsigned long long> totalSum(sz, 0);
	totalSum[0] = primu[0];
	for(int i = 1; i < sz; ++i)
		totalSum[i] = totalSum[i-1] + primu[i];

	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int idx = upper_bound(primu.begin(), primu.end(), n) - primu.begin() - 1;
		if(idx == -1)
			cout << 0 << endl;
		else
			cout << totalSum[idx] << endl;
	}
	return 0;

}