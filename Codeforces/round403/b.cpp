/*input
4
5 10 3 2
2 3 2 4
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

constexpr int maxn = 6 * 10000 + 1;

vector<double> pos(maxn);
vector<double> sp(maxn);

const double eps = 1e-8;

double best = 3.0 * 1e9;

double f(double p)
{
	double aux = 0;
	fr(i, 0, pos.size())
	{
		aux = max(aux, abs(p - pos[i])/(double)sp[i]);
	}
	return aux;
}


double binarySearch(double lo, double hi)
{
	fr(i, 0, 1000)
	{
		double m1 = (hi + 2*lo)/3.0;
		double m2 = (2*hi + lo)/3.0;
		double k1 = f(m1);
		double k2 = f(m2);
		if(k1 < k2)
		{
			hi = m2;
			best = min(best, k1);
		}
		else
		{
			lo = m1;
			best = min(best, k2);
		}
	}
	return best;
}

int main()
{
	int n;
	scanf("%d", &n);
	pos.resize(n);
	sp.resize(n);	
	double mxPos = 0.0;
	double mnPos = 2.0 * 1e9;
	fr(i,0,n)
	{
		scanf("%lf", &pos[i]);
		if(pos[i] > mxPos)
			mxPos = pos[i];
		if(pos[i] < mnPos)
			mnPos = pos[i];
	}
	fr(i,0,n)scanf("%lf", &sp[i]);

	//cout << setprecision(8) << binarySearch(mnPos, mxPos) << endl;
	printf("%.9lf\n", binarySearch(mnPos, mxPos));

	return 0;
}