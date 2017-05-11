/*input
2
9 2
110001111
4 1
1001
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
#define sz(a) (a).size()
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

constexpr int inf = numeric_limits<int>::max();
vvi c;

void genPerm(int lowerLimit, vector<int> cur, int upperLimit, int op)
{
	if(sz(cur) <= op)
		c.pb(cur);
	if(cur.size() >= op)
		return;
	fr(i, 0, upperLimit)
	{
		vi aux = cur;
		aux.pb(i);
		if(aux.size() < op)
			genPerm(i+1, aux, upperLimit, op);
	}
}

int solve(vector<int>& vec)
{

	int greater = inf;
	vi cpy;
	rp(i, c.size())
	{
		cpy = vec;
		rp(j,sz(c[i]))
			cpy[j] = !cpy[j];
		int mx = 1;
		int cur = 1;
		int elem = cpy[0];
		rp(k, sz(vec))
		{
			if(cpy[k] == cur)cur++;
			else
			{
				cur = 1;
				elem = cpy[k];
			}
			if(cur > mx)mx = cur;
		}
		greater = min(greater, mx);
	}
	return greater;
}
int main()
{
	IOS;
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vi nums;
		rp(i, sz(s))nums.pb(s[i] - '0');
		vi q;
		genPerm(0, q, n, k);
		cout << solve(nums) << endl;
	}
	return 0;
}
