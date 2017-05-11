/*input
3
ABC DEF
ABC EFG
ABD OOO

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
#define fu(i, n) fr(i,0,n)
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
	IOS;
	cin.tie(0);
	int x;
	cin >> x;
	vector<pair<string, string> > fiSe;
	set<string> blackList;
	fu(i, x)
	{
		string a, b;
		cin >> a >> b;
		string fis;
		fis += a[0];
		fis += a[1];
		fis += a[2];

		string sec;
		sec += a[0];
		sec += a[1];
		sec += b[0];
		fiSe.pb(mp(fis, sec));
	}

	vector<string> ans;
	fu(i, x)
	{
		if(blackList.find(fiSe[i].fi) == blackList.end())
		{
			ans.pb(fiSe[i].fi);
			blackList.insert(fiSe[i].fi);
			blackList.insert(fiSe[i].se);
		}
		else if(blackList.find(fiSe[i].se) == blackList.end())
		{
			ans.pb(fiSe[i].se);
			blackList.insert(fiSe[i].fi);
			blackList.insert(fiSe[i].se);
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(auto& p : ans)
		cout << p << endl;
	return 0;
}
