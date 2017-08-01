/*input
4 68
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
	int n, a;
	sc2(n, a);
	int v1 = 1, v2 = 2, v3 = 3;
	int r1 = 1, r2 = 2, r3 = 3;
	double bestResp = abs(((n-2)*180.0)/n - a);
	double curAngle = ((n-2)*180.0)/n;
	double diff = curAngle/(n-2);
	while(v3 < n)
	{
		if(curAngle < a)break;
		v3++;
		curAngle -= diff;

		if(abs(a-curAngle) < bestResp)
		{
			r3 = v3;
			bestResp = abs(a-curAngle);
		}
		else break;

	}
	printf("%d %d %d\n", r1, r2, r3);

	return 0;
}
