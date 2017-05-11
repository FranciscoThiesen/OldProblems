/*input
3
15 30 45
*/
#include <bits/stdc++.h>
#include <cstring>
 
using namespace std;
 
#define gcd __gcd
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
set<int> factor(int x)
{
	set<int> fac;
	if(x != 1)
		fac.insert(x);
	for(int i = 2; i <= ceil(sqrt(x)); ++i)
	{
		if(x%i == 0)
		{
			fac.insert(i);
			if(x/i != i && x/i != i)
			fac.insert(x/i);
		}
	}
	return fac;
}

int main()
{
	ios::sync_with_stdio(0);
	int ans = 1;
	unordered_map<int, int> primeSize;
	unordered_multiset<int> lst;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		lst.insert(k);
		if(k != 1)
			primeSize.insert(mp(k, 0));
	}
	for(auto& q : lst)
	{
		int longestSize = 0;
		set<int> primeFact = factor(q);
		for(auto& p : primeFact)
			primeSize[p]++;
		for(auto& p : primeSize)
		{
			ans = max(ans, p.se);
		}
	}
	cout << ans << endl;
	return 0;
}