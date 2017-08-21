#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const long double eps = 1e-8;
// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
	return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

long double dist(ii a, ii b){
	return (a.fi-b.fi)*(a.fi-b.fi) + (a.se - b.se)*(a.se - b.se);
}
int main(){
	vector<ii> pts[2];
	rp(i, 3){
		int x, y;
		cin >> x >> y;
		pts[0].pb(mp(x,y));
	}
	rp(i, 3){
		int a, b;
		cin >> a >> b;
		pts[1].pb(mp(a,b));
	}
	vector<long double> lados[2];
	fr(i,0, 3){
		fr(j, i+1, 3){
			lados[0].pb(dist(pts[0][i], pts[0][j]));
			lados[1].pb(dist(pts[1][i], pts[1][j]));
		}
	}
	sort(all(lados[0]));
	sort(all(lados[1]));
	long double prop = lados[0][0]/lados[1][0];
	bool ok = true;
	fr(i, 1, 3){
		if(cmp_double(lados[0][i]/lados[1][i], prop) != 0){
			ok = false;
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

