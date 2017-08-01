/*input
4 5
1 3 4
1 2 5
5 6 1
1 2 4
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
#define sz(v) (v).size()
#define mt make_tuple
#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const int Inf = 0x3F3F3F3F;
const int negInf = 0xC0C0C0C0;
const ll mod = 1e9 + 7;
const int maxn = 2*(1e5) + 2;

int main()
{
	IOS;
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<set<ii> >  v(maxn);
	vector<map<ll, ll> > bestCost(maxn);

	rp(i, n)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		v[b-a+1].insert(mp(a, c));
	}
	rp(i, maxn)
	{
		ll curBestCost = 4*1e9; 
		bestCost[i][3*1e5] = curBestCost; 
		for(auto it = v[i].rbegin(); it != v[i].rend(); ++it)
		{
			bestCost[i][it->fi] = min(curBestCost, it->se);
			curBestCost = min(curBestCost, it->se);
		}
	}
	long long resp = 3 * 1e9;

	for(int i = 0; i < maxn; ++i)
	{
		for(const auto& p : v[i])
		{
			ll start = p.fi + i - 1;
			ll curCost = 0;
			curCost += p.se; 
			ll missing = x-i;
			if(missing <= 0) continue;  
			if(v[missing].empty()) continue; 
			auto it = bestCost[missing].upper_bound(start); 
			if(it != bestCost[missing].end())
			{
				curCost += it->second;
				if(curCost < resp) resp = curCost;
			}
		}
	}
	if(resp >= 3*1e9)
		cout << -1 << endl;
	else
		cout << resp << endl;
	return 0;
}
