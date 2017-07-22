/*input
2 100000
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



double bSearch(double minBase, double minHeight, double area, double maxHeight, double maxBase)
{
	double hi = maxBase, lo = minBase, tempH, mid, avgBase;
	rp(i, 200)
	{
		mid = (hi+lo)/2.0;
		avgBase = (mid + minBase)/2.0;
		if(avgBase* ((mid * maxHeight)-minHeight) < area)
		{
			lo = mid;
		}
		else
			hi = mid;
	}
	return mid;
}
int main()
{
	IOS
	double n, h;
	cin >> n >> h;
	double area = h/2.0;
	double pieceArea = area/n;
	double curH = 0;
	double curB = 0;
	rp(i, n-1)
	{
		curB = bSearch(curB, curH, pieceArea, h, 1);
		curH = curB * h;
		printf("%.10lf\n", curH);
	}
	return 0;
}
