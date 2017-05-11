/*input
3
2 1 1 3 2 3
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

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a, 0 b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

int main()
{
	int x;
	sc(x);
	unordered_map<int, int> mapa;
	int table = 0;
	int mx = 0;
	fr(i, 0, 2*x)
	{
		int k;
		sc(k);
		if(mapa[k] == 1)
		{
			mapa[k] = 0;
			table--;
		}
		else
		{
			mapa[k] = 1;
			table++;
		}
		if(table > mx)
			mx = table;
	}
	pr(mx);
	return 0;
}
