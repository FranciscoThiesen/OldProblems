/*input
7
1 1 2 3 1 4
3 3 1 1 1 2 3
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
const int maxn = 1e4 + 10;

vi g[maxn];
vector<int> color(maxn, 0);


int solve(int root){
	int cost = 1; // pintar o no da cor certa
	int eq = 0;
	for(const int& v : g[root]){
		if(color[v] == color[root]){
			cost += solve(v) - 1;
		}
		else cost += solve(v);
	}
	return cost;
}

int main(){
	init();
	int n;
	cin >> n;
	rep(i,2,n+1){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	rep(i, 1, n+1){
		cin >> color[i];
	}
	cout << solve(1) << endl;
	return 0;
}

