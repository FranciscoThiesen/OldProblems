/*input
7 7 5
2 3
3 4
4 5
7 6
1 3
2 7
1 7
4 2
2 3
6 7
3 7
5 2
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
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

const int maxn = 1013;

vi g[maxn];

int buceta = 0, n, m, q, a, b, x, y;

void dfs(int curNode, int target, vector<bool>& visited){
	if(buceta>1) return;
	if(curNode == target) buceta++;
	for(const int& v : g[curNode]){
		if(visited[v] == false){
			visited[v] = true;
			dfs(v, target, visited);
			visited[v] = false;
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	rep(i,0,m){
		scanf("%d %d", &a, &b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i,0,q){
		scanf("%d %d", &x, &y);
		--x;--y;
		vector<bool> vis(n, false);
		vis[x] = true;
		buceta = 0;
		dfs(x, y, vis);
		if(buceta == 1) puts("1");
		else puts("0");
	}
	return 0;
}

