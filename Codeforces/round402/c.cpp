/*input
5 3
3 4 7 10 3
4 5 5 12 5
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

int main()
{
	IOS
	int n, k;
	cin >> n >> k;
	vi a(n);
	vi b(n);
	rp(i, n)cin >> a[i];
	rp(i, n)cin >> b[i];
	vector<int> diff;
	rp(i,n)diff.pb(b[i] - a[i]);
	int buyNow = 0;
	rp(i, n)buyNow+= a[i];
	int rmv = n-k;
	sort(all(diff));
	rp(i, rmv)
	{
		if(diff[i] > 0)
			break;
		else
			buyNow += diff[i];
	}
	cout << buyNow << endl;
	return 0;
}
