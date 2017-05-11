/*input
4
-1 20 40 77 119
30 10 73 50 107
21 29 -1 64 98
117 65 -1 -1 -1
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

int mat[120][5] = {{0}};

int main()
{
	IOS
	int n;
	cin >> n;
	vector<int> solved(5, 0);
	vector<pair<double, double> > ratios;
	ratios.pb(mp(1.0,0.5));
	ratios.pb(mp(0.5,0.25));
	ratios.pb(mp(0.25,0.125));
	ratios.pb(mp(0.125,0.0625));
	ratios.pb(mp(0.625,0.03125));
	ratios.pb(mp(0.03125,0.0));
	rp(i,n)
	{
		rp(j, 5)
		{
			cin >> mat[i][j];
			solved[j] += (mat[i][j] != -1)? 1 : 0;
		}
	}
	vector<int> good;
	vector<int> bad;
	rp(i, 5)
	{
		if(mat[0][i] != -1)
		{
			if(mat[1][i] == -1)
				good.pb(i);
			else if(mat[1][i] > mat[0][i])
				good.pb(i);
			else if(mat[1][i] < mat[0][i])
				bad.pb(i);
		}
		else
		{
			if(mat[1][i] != -1)
				bad.pb(i);
		}
	}
	int vBest = 0, pWorst = 0;
	
	for(auto p : good)
	{
		vBest = (int)3000*(1 - (double)mat[0][p]/250);
		if(mat[1][p] != -1)
			 pWorst = (int)3000*(1 - (double)mat[1][p]/250);
	}
	for(auto p : bad)
	{
		if(mat[0][p] != -1)
		{
			vBest = (int)500*(1 - (double)mat[0][p]/250);
		}
		 pWorst = (int)500*(1 - (double)mat[1][p]/250);
	}
	if(vBest <= pWorst)
	{
		cout << vBest << " " << pWorst << endl;
		cout << -1 << endl;
		return 0;
	}
	// Os problemas que Petya Nao resolveu devem valer o minimo possivel
	// Vamos tentar greedy, fazer as mudancas que diminuem a diferenca
	return 0;
}
