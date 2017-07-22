/*input
1 2 10
11
15 7
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define gcd __gcd
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;

ll office;

bool cmp(ll a, ll b)
{
	return abs(a-office) <= abs(b-office);
}

int main()
{
	int n, b;
	cin >> n >> b >> office;	
	vector<ll> j(n);
	vector<ll> p(b);
	for(int i = 0; i < n; ++i) cin >> j[i];
	for(int i = 0; i < b; ++i) cin >> p[i];
	sort(all(j), cmp);
	ll resp = 0;
	for(auto v : j)
	{
		ll best = 1e15;
		int bestPos;
		for(int i = 0; i < b; ++i)
		{
			ll cur = abs(p[i]-v) + abs(p[i]-office);
			if(cur < best)
			{
				bestPos = i;
				best = cur;
			}
		}
		p[bestPos] = 1e15;
		resp = max(resp, best);
	}
	cout << resp << endl;
}