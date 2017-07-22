#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const double eps = 1e-9

int main()
{
	IOS;
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> elem(n);
	forn(i, n)
		cin >> elem[i];
	
	int prev = elem[0];
	int size = 1;
	vector<ii> elemFreq;

	for(int i = 1; i < n; ++i)
	{
		if(elem[i] == prev)
			size++;
		else
		{
			elemFreq.pb(mp(prev, size));
			prev = elem[i];
			size = 1;
		}
	}
	elemFreq.pb(mp(prev, size));

}
