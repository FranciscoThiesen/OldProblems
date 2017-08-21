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

const int maxn = 3001;
int t, n, b, c;

int a[maxn];

ll solve(ll dist){
	ll resp = 0;
	ll rest = dist%b;
	rp(i, b){
		if(rest > 0){
			resp += (dist/b + 1) * (dist/b + 1);
			rest--;
		}
		else resp += (dist/b)*(dist/b);
	}
	return resp;
}	

main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &b, &c);
		memset(a, 0, sizeof a);
		rp(i, n) scanf("%d", &a[i]);
		assert(c == 1);
		sort(a, a+n);
		ll maxDist = a[n-1] - a[0];

		printf("%lld\n", solve(maxDist));
	}
}
