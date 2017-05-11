/*input
9
3 2 5 5 2 3 3 3 2
4 1 4 1 1 2 4 4 1
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
	int n;
	cin >> n;
	vi a(6, 0);
	vi b(6, 0);
	int x;
	rp(i, n)
	{
		cin >> x;
		a[x]++;
	}
	rp(i, n)
	{
		cin >> x;
		b[x]++;
	}
	int chgA = 0;
	int chgB = 0;
	bool pos = true;
	rp(i, 6)
	{
		if((a[i] + b[i])%2 == 1)
		{
			pos = false;
			break;
		}
		if(a[i] > b[i])
			chgA += (a[i] - b[i])/2;
		else if(b[i] > a[i])
			chgB += (b[i] - a[i])/2;
	}
	if(pos && chgA == chgB)
	{
		cout <<chgA << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}
