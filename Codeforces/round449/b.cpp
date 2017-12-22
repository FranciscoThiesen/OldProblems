/*input
100001 1000000000000000000
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
int mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

ll brute(int tot){
	ll dgSz = 2;
	vector<vector<ll> > nums(1000);
	vector<ll> prevPrev;
	vector<ll> st{0,11,22,33,44,55,66,77,88,99};
	nums[2] = vector<ll>{0,11,22,33,44,55,66,77,88,99};
	ll seen = 0;
	ll sum = 0;
	tot++;
	while(tot){
		vector<ll> nxt;
		ll nxDg = dgSz + 2;
		// if(nxDg == 4){
		// 	rep(i,1,10){
		// 		nxt.pb(1000 * i + i);
		// 	}
		// }
		for(const ll& v : nums[dgSz]){
			sum += (v % mod);
			sum %= mod;
			tot--;
			if(tot == 0) return (sum % mod);
		}
		//cout << endl << endl;
		rep(i,1,10){
			for(int k = 2; k < nxDg; k += 2){
				for(const ll& v : nums[k]){
					ll q = (i*powmod(10, nxDg-1) + v*powmod(10, (nxDg - k)/2) + i)%mod;
					nums[nxDg].pb(q);
				}
			}
		}

		if(tot == 0) return sum%mod;
		dgSz = nxDg;
	}
	return sum % mod;
}

int main(){
	init();
	int k;
	cin >> k >> mod;
	cout << brute(k) << endl;
	return 0;
}

