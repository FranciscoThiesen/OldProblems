/*input

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
const int maxn = 101;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }
int t, n, m;
char mat[maxn][maxn];

int solve(){
	vector<string> v;
	v.pb("RG");
	v.pb("GR");
	int ans = inf;
	rep(i,0,2){
		int cost = 0;
		rep(lin, 0, n){
			rep(col, 0, m){
				if(mat[lin][col] == 'G' && v[i][(lin+col)%2] == 'R') cost += 3;
				if(mat[lin][col] == 'R' && v[i][(lin+col)%2] == 'G') cost += 5;
			}
		}
		ans = min(ans, cost);
	}
	return ans;
}

int main(){
	init();
	cin >> t;
	rep(i,0,t){
		cin >> n >> m;
		rep(i,0,n){
			rep(j,0,m){
				cin >> mat[i][j];
			}
		}
		cout << solve() << endl;
	}
	return 0;
}

