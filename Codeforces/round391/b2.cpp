/*input
4
3 15 25 45
*/
#include <bits/stdc++.h>
#include <cstring>
 
using namespace std;
 
#define gcd __gcd
#define ll long long
#define pb push_back
#define fi first
#define se second

vector<int> factor(int x)
{
	vector<int> fac;
	fac.pb(x);
	for(int i = 2; i <= ceil(sqrt(x)); ++i)
	{
		if(x%i == 0)
		{
			fac.pb(i);
			fac.pb(x/i);
		}
	}
	return fac;
}

int main()
{
	ios::sync_with_stdio(0);
	int ans = 1;
	unordered_map<int, int> primeSize;
	unordered_set<int> lst;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		lst.insert(k);
	}
	for(auto& q : lst)
	{
		int longestSize = 0;
		if(n != 1)
		{
			vector<int> primeFact = factor(q);
			for(auto& p : primeFact)
			{
				cout << q << " " << p << endl;
				if(primeSize.find(p) != primeSize.end())
					longestSize = ((primeSize[p] > longestSize)? primeSize[p] : longestSize);
			}
			for(auto& p : primeFact)
				primeSize[p] = longestSize + 1;
		}
		for(auto& p : primeSize)
		{
			if(lst.find(p.fi) != lst.end())
			{
				ans = max(ans, p.se);
			}
		}
	}
	cout << ans << endl;
	return 0;
}