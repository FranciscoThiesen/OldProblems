/*input
3 5
abc
xaybz
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
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int Inf = 0x3F3F3F3F;
const int negInf = 0xC0C0C0C0;
const ll mod = 1e9 + 7;

int main()
{
	int na, nb;
	cin >> na >> nb;
	string s, t;
	cin >> s >> t;
	vector<int> ans;
	int best = Inf;
	for(int start = 0; start <= nb-na; ++start)
	{
		int cur = 0;
		vector<int> pos;
		for(int i = 0; i < na; ++i)
		{

			if(s[i] != t[i+start]){
				cur++;
				pos.pb(i+1);
			}
		}
		if(cur < best)
		{
			best = cur;
			ans = pos;
		}
	}
	cout << best << endl;
	for(auto& p : ans)
		cout << p << " ";
	cout << endl;

	return 0;
}
