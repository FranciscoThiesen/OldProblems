/*input
abac
aba
4 1 2 3
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
#define rp(a, b) fr(a, 0,  b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);
#define sz(x) (x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

string t, p;

vector<int> rem;

int ans = 0;

bool find(string &t, string &p)
{
	if(p.size() > t.size())
		return false;
	int start = 0;
	bool pos = true;
	int match = 0;
	rp(i, p.size())
	{
		fr(j, start, t.size())
		{
			if(t[j] == p[i])
			{
				match++;
				start = j+1;
				break;
			}
		}
	}
	if(match == p.size())
		return true;
	return false;
}

void solve(int k)
{
	int lo = 0;
	int hi = k-1;
	int mid;
	string aux(k, '#');
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		memset(aux, '#', sizeof aux);
		for(int i = mid+1; i < k; ++i)
		{
			aux[rem[i]] = t[rem[i]];
		}
		string f;
		for(auto& p : aux)
			if(p != '#')
				f += p;
		if(f.size() < p.size())
		{
			hi = mid-1;
		}
		else
		{
			if(find(f, p))
			{
				ans = max(ans, mid+1);
				lo = mid+1;
			}
			else
				hi = mid-1;
		}
	}
}
int main()
{
	cin >> t >> p;
	rp(i, t.size())
	{
		int x;
		cin >> x;
		rem.pb(x-1);
	}
	solve((int)t.size());
	cout << ans << endl;
	return 0;
}
