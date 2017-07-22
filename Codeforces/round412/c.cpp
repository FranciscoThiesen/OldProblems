/*input
4
1500 1500
1300 1300
1200 1200
1400 1400
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

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

int main()
{
	IOS
	int n;
	cin >> n;
	vii rated(n);
	vi st(n);
	rp(i,n)
	{
		int a, b;
		cin >> a >> b;
		if(a != b)
		{
			cout << "rated" << endl;
			return 0;
		}
		st[i] = a;
		rated[i] = mp(a, b);
	}
	vi cpy = st;
	sort(cpy.rbegin(), cpy.rend());
	bool k = false;
	rp(i,n)
	{
		if(cpy[i] != st[i])
		{
			cout << "unrated" << endl;
			return 0;
		}
	}
	cout << "maybe" << endl;
	return 0;
}