/*input
100 9
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
#define rp(a, b) fr(a, 0, b)
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

vector<vi> combinations;

string n;

int sz;

void genPerm(vi curPerm, int last, int sz)
{
	if(!curPerm.empty())
	{
		combinations.pb(curPerm);
	}
	for(int i = 0; i < sz; ++i)
	{
		if(i > last)
		{
			vi tmp = curPerm;
			tmp.pb(i);
			genPerm(tmp, i, sz);
		}
	}
}
int main()
{

	cin >> n;
	int k;
	int sz = (int)n.size();
	cin >> k;
	int a = 1;
	rp(i, k) a*=10;
	int mn = 20;
	vi ep;
	genPerm(ep, -1, sz);
	for(int i = 0; i < combinations.size(); ++i)
	{
		string aux;
		for(auto& p : combinations[i])
		{
			aux += n[p];
		}
		if(aux[0] == '0' && aux.size() > 1)
			continue;
		int x = stoi(aux);
		if(x%a == 0)
		{
			mn = min(mn, sz - (int)aux.size());
		}
	}
	cout << mn << endl;
	return 0;
}
