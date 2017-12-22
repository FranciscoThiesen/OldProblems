/*input
6
1 2 3 4 5
1 2 5 6 1
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i) = (a); (i) < (n); ++(i))
#define per(i,a,n) for(int (i) = (n-1); (i) >= (a); --(i))
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define SZ(a) ((int)(a.size()))
#define init() ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

const int maxn = 3*1e5 + 13;

int n, a, b, x, y;

vi g[maxn][2];
ll id[maxn];
int visited[maxn][2];
vector<ii> edges[2];
unordered_map<ll, int> memo;
mt19937_64 xablau(time(0));


// Para cada no de uma arvore, subTreeHash[i][0/1] = (hash da subarvore, tam da subarvore)
ii subTreeHash[maxn][2];

void compute(int root, int idx){
	visited[root][idx] = 1;
	ii resp = mp(id[root], 1);
	for(const int& v : g[root][idx]){
		if(!visited[v][idx]){
			compute(v, idx);
			resp.fi ^= subTreeHash[v][idx].fi;
			resp.se += subTreeHash[v][idx].se;
		}
	}
	subTreeHash[root][idx] = resp;
}

int main(){	
	scanf("%d", &n);
	rep(i,0,n){
		id[i] = xablau();
	}
	// lendo as arestas arv 1
	rep(i,1, n){
		scanf("%d", &x);
		--x;
		g[i][0].pb(x);
		g[x][0].pb(i);
		edges[0].pb(mp(i, x));
	}
	// lendo as arestas arv 2
	rep(i,1, n){
		scanf("%d", &x);
		--x;
		g[i][1].pb(x);
		g[x][1].pb(i);
		edges[1].pb(mp(i, x));
	}

	compute(0,0);
	compute(0,1);

	for(const ii& e : edges[0]){
		ii t1 = subTreeHash[e.fi][0];
		ii t2 = subTreeHash[e.se][0];
		if(t1.se < t2.se) memo[t1.fi]++;
		else if(t1.se == t2.se){
			if(t1.fi < t2.fi) swap(t1,t2);
			memo[t1.fi]++;
		}
		else memo[t2.fi]++;
	}
	ll ans = 0;
	for(const ii& e : edges[1]){
		ii t1 = subTreeHash[e.fi][1];
		ii t2 = subTreeHash[e.se][1];
		if(t1.se < t2.se) ans += memo[t1.fi];
		else if(t2.se > t1.se ) ans += memo[t2.fi];
		else{
			ans += memo[t1.fi] + memo[t2.fi];
		}
	}
	printf("%lld\n", ans);
	return 0;
}