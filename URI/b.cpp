#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ii pair<int, int>

typedef long long ll;
int main()
{
	int n, a;
	cin >> n >> a;
	vector<pair<ll, ll> > ajudantes(a);
	vector<ll> g;
	for(int i = 0; i < n; ++i)
	{
		ll x;
		cin >> x;
		g.pb(x);
	}
	// o pair da fila tera a informacao 
	for(int i = 0; i < n; ++i)
	{
		int bestIdx = -1;
		ll inc = numeric_limits<ll>::max();
		ll tmp;
		for(int j = 0; j < a; ++j)
		{
			ii k = ajudantes[j];
			tmp = g[i]*(k.second+1) + k.first;
			if(tmp < inc)
			{
				inc = tmp;
				bestIdx = j;
			}
		}
		ajudantes[bestIdx].second += 1;
		ajudantes[bestIdx].first += g[i];
	}

	unsigned long long ans = 0;
	for(int i = 0; i < a; ++i)
		ans += ajudantes[i].first * ajudantes[i].second;
	cout << ans << endl;
	return 0;
}