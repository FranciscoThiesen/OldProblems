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

ll L, D;
int n;
vector<pair<ll, bool> > coord;

void solve(){
	int tam = sz(coord);
	double resp = 0;
	rp(i, tam-1){
		auto start = coord[i];
		auto end = coord[i+1];
		if(start.se == false && end.se == true){
			ll s = end.fi - start.fi;
			double avg = s/4.0;
			resp += (s* avg);
		}	
	}
	printf("%.12f\n", resp/(double) D);
}

int main(){
	scanf("%lld %lld %d", &D, &L, &n);
	coord.pb(mp(L,0));
	rp(i, n){
		ll x;
	    scanf("%lld", &x);
		coord.pb(mp(x, 1));
		if(x+L < D){
			coord.pb(mp(x+L, 0));
		}
	}
	coord.pb(mp(D, 1));
	sort(all(coord));
	solve();
	return 0;
}
