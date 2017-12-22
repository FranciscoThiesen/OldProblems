/*input
3
2
3
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

typedef pair<int, int> bezout;

bezout find_bezout(int x, int y) {
	if (y == 0) return bezout(1, 0);
	bezout u = find_bezout(y, x % y);
	return bezout(u.second, u.first - (x/y) * u.second);
}

const int maxn = 10000001;
int main(){
	init();
	ll a, b, c;
	cin >> a >> b >> c;
	ll gcd = __gcd(b, c);
	if(a%gcd == 0){
		vector<ll> bn;
		vector<ll> cn;
		int end = 0;
		rep(i,0,maxn+3){
			if(b*i > a){
				end = i-1;
				break;
			}
			bn.pb(b*i);
		}
		ll mul = 0;
		ll cur = 0;
		while(cur <= a){
			ll missing = a-cur;
			int idx = lower_bound(all(bn), missing) - bn.begin();
			if(idx <= end){
				if(bn[idx] == missing){
					cout << "YES" << endl << idx << " " << mul << endl;
					return 0;
				}
			}
			mul++;
			cur += c;
		}
	}
	cout << "NO" << endl;
	return 0;
}

