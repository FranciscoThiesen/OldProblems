// https://www.codechef.com/IOIPRAC/problems/INOI1201
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
 
bool cmp(ii a, ii b) { return a.se >= b.se;}
int main()
{
	int n, a, b, c;
	sc(n);
	vector<ii> vec(n);
	rp(i, n)
	{
		sc3(a,b,c);
		vec[i].fi = a;
		vec[i].se = b + c;
	}
	sort(all(vec), cmp);
	long long startTime = 0;
	long long resp = 0;
	for(auto const& evt : vec)
	{
		resp = max(resp, startTime + evt.fi + evt.se);
		startTime += evt.fi;
	}	
	printf("%lld\n", resp);
	return 0;
}