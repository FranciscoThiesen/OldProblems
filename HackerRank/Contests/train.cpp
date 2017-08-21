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
const int maxn = 1e5 + 10;
const int logmax = 20;

vi g[maxn];

int t, n, a, b, c, v1, v2, v3;
int vd[maxn][logmax], dad[maxn], mrc[maxn];

void dfs(int a, int pai, int lvl){
	mrc[a] = lvl;
	dad[a] = pai;
	for(int v : g[a]) if(mrc[v] == 0) dfs(v, a, lvl+1);
}

void build(int n){
	rp(i, n) vd[i][0] = dad[i];
	fr(j, 1, logmax){
		rp(i, n){
			vd[i][j] = vd[vd[i][j-1]][j-1];
		}
	}
}

int dist(int a, int b){
	int d = 0;
	if(mrc[a] > mrc[b]) swap(a,b);
	for(int i = logmax-1; i >= 0; --i){
		if(mrc[vd[b][i]] > mrc[a]){
			b = vd[b][i];
			d += 1<<i;
		}
	}
	if(mrc[b] != mrc[a]) {
		d++;
		b = vd[b][0];
	}
	for(int i = logmax - 1; i >= 0; i--) {
		if(vd[b][i] != vd[a][i]) {
			a = vd[a][i];
			b = vd[b][i];
			d += 2*(1 << i);
		}
	}
	if(b != a) d += 2;
	return d;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%d %d %d", &a, &b, &c);
		scanf("%d %d %d", &v1, &v2, &v3);
		rp(i, n-1){
			int x, y;
			scanf("%d %d", &x, &y);
			g[--x].pb(--y);
			g[y].pb(x);
		}
	}
	return 0;
}

