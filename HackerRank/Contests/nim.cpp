#include <bits/stdc++.h>

using namespace std;

#define F(i, a, n) for(int i = a; i < n; ++i)
#define FD(i, n, a) for(int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define mod 1000 * 1000 * 1000 + 7
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

ll powmod(ll a, ll b)
{
	ll res = 1;
	a%=mod;
	assert(b >= 0);
	for(; b; b >>= 1)
	{
		if(b&1)
		{	
			res = res*a%mod;
			a = a*a%mod;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> pile;
		for(ll a = 0; a < n; ++a)
		{
			ll k;
			cin >> k;
			pile.pb(k);
		}

		ll accu = pile[0];
		for(int i = 1; i < n; ++i)
			accu ^= pile[i];

		bool win = true;
		cout << accu << endl;
		if(accu == 0)
		{
			win = false;
		}

		if(n%2 == 1)
		{
			if(win == true)
				win = false;
			else
				win = true;
		}
		if(win)
			cout << "W" << endl;
		else
			cout << "L" << endl;
	}
	return 0;
}
