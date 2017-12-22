/*input
6
120 110 23 34 25 45
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
const ll mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }


vector<ll> sqr;

ll bestMove(ll x){
	ll idx = upper_bound(all(sqr), x) - sqr.begin();
	return min(sqr[idx] - x, x - sqr[idx-1]);
}

bool is_square(ll x){
	ll k = sqrt(x);
	while(k*k < x) k++;
	while(k*k > x) k--;
	return (k*k == x);

}

ll nop(ll x){
	if(x == 0) return 2;
	if(is_square(x)) return 1;
	return 0;
}

int main(){
	init();
	for(ll i = 0; i*i < mod + 100000; ++i) sqr.pb(1ll*i*i);
	int n;
	cin >> n;
	vector<ll> nums(n);
	multiset<ll> recover;
	ll ans = 0;
	rep(i,0,n){
		cin >> nums[i];
		ans += bestMove(nums[i]);
		recover.insert(nop(nums[i]) - bestMove(nums[i]));
	}
	multiset<ll>::iterator k = recover.begin();
	rep(i,0,n/2){
		ans += *k;
		++k;
	}
	cout << ans << endl;
	return 0;
}

