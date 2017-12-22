/*input
4 1 4
2 3
4 1
1 2
3 2
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
int main(){
	init();
	int n, e1, e2;
	cin >> n >> e1 >> e2;
	int best = 0;
	// up, down
	int a1 = 0;
	// up, up
	int a2 = 0;
	// down, up
	int a3 = 0;
	// down, down
	int a4 = 0;
	vector<ii> p(n);
	rep(i,0,n){
		int x, y;
		cin >> x >> y;
		p[i] = mp(x,y);
	}
	int resp = 0;
	rep(i,0,4){
		int ans = 0;
		int a, b;
		if(i == 0){
			a = 1;
			b = -1;
		}
		else if(i == 1){
			a = 1;
			b = 1;
		}
		else if(i == 2){
			a = -1;
			b = 1;
		}
		else{
			a = b = -1;
		}
		rep(i,0,n){
			int ok = 0;
			if(p[i].fi < p[i].se){
				if(a == 1){
					if(e1 <= p[i].fi) ok = 1;
				}
				if(b == 1){
					if(e2 <= p[i].fi) ok = 1;
				}
				ans += ok;
			}
			else if(p[i].fi > p[i].se){
				if(a == -1){
					if(e1 >= p[i].fi) ok = 1;
				}
				if(b == -1){
					if(e2 >= p[i].fi) ok = 1;
				}
				ans += ok;
			}
		}
		resp = max(ans, resp);
	}
	cout << resp << endl;
	return 0;
}

