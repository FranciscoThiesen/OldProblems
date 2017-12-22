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

int n, h, m, w;

int main(){
	cin >> h >> w >> n >> m;
	vector<int> cutH(n), cutV(m);
	rp(i, n) cin >> cutH[i];
	rp(i, m) cin >> cutV[i];
	sort(all(cutH));
	sort(all(cutV));
	vector<ii> intervH, intervV;
	intervV.pb(mp(0, h));
	intervH.pb(mp(0, w));
	for(const int& line : cutH){
		ii tmp = intervV.back();
		ii new1 = mp(tmp.fi, line);
		ii new2 = mp(line, tmp.se);
		intervV.pop_back();
		intervV.pb(new1);
		intervV.pb(new2);
	}
	for(const int& line : cutV){
		ii tmp = intervH.back();
		ii new1 = mp(tmp.fi, line);
		ii new2 = mp(line, tmp.se);
		intervH.pop_back();
		intervH.pb(new1);
		intervH.pb(new2);
	}
	map<int, int> faixaVertical;
	for(const ii& x : intervV){
		faixaVertical[x.se - x.fi]++;
	}
	ull resp = 0;
	for(const ii& x2 : intervH){
		int s = x2.se - x2.fi;
		resp +=  faixaVertical[s];
	}
	cout << resp << endl;
	return 0;
}

