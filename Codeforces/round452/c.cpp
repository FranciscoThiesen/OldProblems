/*input
2
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

pair<long long, long long> solve(int n){
	long long soma = 0;
	long long ret = (n%4 == 0 || n%4 == 3)? 0 : 1;
	if(n%4 == 0){
		cout << 0 << endl;
		cout << n/2 << " ";
		rep(i,1,n+1){
			if(i%4 == 0 || i%4 == 1){
				cout << i << " ";
			}
		}
	}
	else if(n%4 == 3){
		vi t;
		rep(i,1,n/4 + 1) t.pb(i);
		rep(i, n - n/4, n+1) t.pb(i);
		cout << 0 << endl;
		cout << SZ(t) << " ";
		for(auto& v : t) cout << v << " ";
	}
	else if(n%4 == 1){
		vi t;
		rep(i,1,n/4 + 2) t.pb(i);
		rep(i, n - n/4 + 1, n+1) t.pb(i);
		cout << 1 << endl;
		cout << SZ(t) << endl;
		for(auto& v : t) cout << v << " ";
	}
	else{
		cout << 1 << endl;
		vi q;
		int tot = 0;
		rep(i,1,n+1){
			if(i%4 == 0 || i%4 == 1){
				q.pb(i);
				tot++;
			}
		}
		cout << tot << " ";
		for(auto& v : q) cout << v << " ";
	}
	cout << endl;
	return mp(ret, soma);
}


int main(){
	init();
	int n;
	cin >> n;
	solve(n);
	return 0;
}

