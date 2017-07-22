/*input
5
13 900000007 900000007 900000009
13 900000007 900000007 900000009
13 900000007 900000007 900000009
13 900000007 900000007 900000009
13 900000007 900000007 900000009
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(x) (x).size()

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);
#define gcd __gcd

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

ll lcm(ll a, ll b){ return a*b / (gcd(a,b));}

int main()
{
	IOS
	int t;
	cin >> t;
	while(t--)
	{
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if(a == b && x != y)
		{
			cout << -1 << endl;
			continue;
		}
		if(x != 0 && a == 0)
		{
			cout << -1 << endl;
			continue;
		}
		ll g = gcd(x, y);
		if(x/g == a && y/g == b)
		{
			cout << 0 << endl;
			continue;
		}
		ll mult = max(ceil(x/(double)a), ceil(y/(double)b) );
		
		ll stA, stB;
		while(true)
		{
			stA = a*mult;
			stB = b*mult;
			if(stA-x <= stB-y)
			{
				cout << stB-y << endl;
				break;
			}
			mult++;
		}
	}
	return 0;
}