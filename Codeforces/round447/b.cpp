/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
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


bool checkOk(vi& perm, int x){
	bool ok = true;
	rep(i,0,x){
		int prod = 1;
		rep(j, i*x, i*x+x){
			cout << "olhando pos = " << j << endl;
			prod *= perm[j];
		}
		cout << endl;
		if(prod == -1) return false;
	}
	rep(i, 0, x){
		int p = 1;
		int c = 0;
		for(int j = i; c++ < x; j += x){
			p *= perm[j];
			cout << "olhando pos2 = " << j << endl;
		}
		cout << endl;
		if(p == -1) return false;
	}
	return true;
}

void backtrack(int n){
	vector<vector<int> > perm;
	rep(i, 0, (1 << (n*n))){
		vector<int> in(n*n, -1);
		rep(j,0,(n*n)){
			if(i & (1 << j)){
				in[j] = 1;
			}
		}
		if(checkOk(in, n)) perm.pb(in);
	}
	cout << "temos " << SZ(perm) << " matrizes validas " << endl;
}

int main(){
	init();
	ll a, b, k;
	cin >> a >> b >> k;
	// if(a > b) swap(a,b);
	// if(a == 1ll){
	// 	if(b%2 == 0 && k == -1ll){
	// 		cout << 0 << endl;
	// 	}
	// 	else cout << 1 << endl;
	// }
	// else{
	// 	ll ans = 1;
	// 	ll rowPos = 0;
		

	// }
	backtrack(5);
	return 0;
}

