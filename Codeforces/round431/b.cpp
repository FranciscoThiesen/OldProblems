/*input
5
1000000000 0 0 0 0
*/
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

bool ok(vector<pair<ll, ll> >& v, ll C1, ll C2, ll C3){
	if(v.size() == 0) return false;
	if(v.size() <= 1) return true;
	else{
		auto p1 = v[0];
		auto p2 = v[1];
		ll c1 = (p1.se - p2.se);
		ll c2 = (p2.fi - p1.fi);
		ll k = p1.fi * p2.se - p1.se * p2.fi;
		if(p1.se == p2.se){
			c1 = 0;
			c2 = 1;
			k = -p2.se;
		}
		if((c1 == 0 && C1 != 0) || (c1 != 0 && C1 == 0)) return false;
		else if(c1 != 0 && C1 != 0){
			if(c1*C2 != c2*C1) return false;
		}
		for(int i = 2; i < (int)v.size(); ++i){
			if(v[i].fi * c1 + v[i].se * c2 + k != 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	vector<pair<ll, ll> > pts;
	rp(i, n){
		ll x;
		cin >> x;
		pts.pb(mp(i+1, x));
	}
	rp(i, 1){
		fr(j, i+1, n){
			vector<pair<ll, ll> > nope;
			ll c1 = (pts[i].se - pts[j].se);
			ll c2 = (pts[j].fi - pts[i].fi);
			ll k = (pts[i].fi * pts[j].se - pts[i].se * pts[j].fi);
			if(pts[i].se == pts[j].se){
				c1 = 0;
				c2 = 1;
				k = -pts[i].se;
			}
			rp(q, n){
				if(pts[q].fi * c1 + pts[q].se * c2 + k != 0){
					nope.pb(pts[q]);
				}
			}
			if(ok(nope, c1, c2, k)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rp(i, 2){
		fr(j, i+1, n){
			vector<pair<ll, ll> > nope;
			ll c1 = (pts[i].se - pts[j].se);
			ll c2 = (pts[j].fi - pts[i].fi);
			ll k = (pts[i].fi * pts[j].se - pts[i].se * pts[j].fi);
			if(pts[i].se == pts[j].se){
				c1 = 0;
				c2 = 1;
				k = -pts[i].se;
			}
			rp(q, n){
				if(pts[q].fi * c1 + pts[q].se * c2 + k != 0){
					nope.pb(pts[q]);
				}
			}
			if(ok(nope, c1, c2, k)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}

