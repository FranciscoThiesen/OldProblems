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
	return 0;
}
unordered_set<ull> combinations;

ull lower, upper;

void genPerm(ull cur)
{
	if(cur > upper)
		return;
	if(cur >= lower && cur <= upper)
		combinations.insert(cur);
	if(!cur)
	{
		genPerm(2);
		genPerm(3);
		genPerm(5);
		genPerm(7);
	}
	else
	{
		cur *= 10;
		genPerm(cur + 2);
		genPerm(cur + 3);
		genPerm(cur + 5);
		genPerm(cur + 7);
	}
	
}

bool prim(ull n)
{
	if(n == 2 || n == 3)
		return true;
	if(n%6 != 1 && n%6 != 5)
		return false;
	if(n%2 == 0)
		return false;
	for(int i = 3; i <= ceil(sqrt(n)); i+=2)
	{
		if(!(n%i))
			return false;
	}	
	return true;
}

int main()
{
	scanf("%llu %llu", &lower, &upper);
	genPerm(0);
	int ans = 0;
	for(auto& p : combinations)
		if(prim(p))
			ans++;
	printf("%d\n", ans);
	return 0;
}
