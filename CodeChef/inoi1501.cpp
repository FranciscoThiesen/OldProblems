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

const int N = 1e6 + 5;

ll a[N], b[N], accu[N], bccu[N];
int n;

int main(){
	scanf("%d", &n);
	fr(i,0,n)scanf("%lld", &a[i+1]);
	fr(i,0,n)scanf("%lld", &b[i+1]);
	accu[0] = bccu[0] = 0;
	fr(i,1,n+1){
		accu[i] = accu[i-1] + a[i];
	}
	fr(i,1,n+1){
		bccu[i] = bccu[i-1] + b[i];
	}
	ll mx = -inf;
	set<ll> diff;
	ll best[n+1][2];
	for(int i = 1; i <= n; ++i){
		if(i == 1) best[i][0] = a[i];
		else{
			best[i][0] = *(diff.rbegin()) + a[i] + bccu[i-1];
		}
		diff.insert(a[i] - bccu[i]);
	}
	diff.clear();
	for(int i = n; i > 0; --i){
		if(i == n) best[i][1] = a[i];
		else{
			best[i][1] = *(diff.rbegin()) + bccu[n] + bccu[i-1] + a[i];
		}
		diff.insert(a[i] - bccu[i]);
	}
	fr(i,1,n+1) mx = max(mx, max(a[i], max(best[i][0], best[i][1])));
	printf("%lld\n", mx);
	return 0;
}
