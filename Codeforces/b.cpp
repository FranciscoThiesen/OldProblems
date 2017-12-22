/*input
5
100 160 50 30 20
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
    init()
	ll n, x, k;
	cin >> n >> x >> k;
	vector<ll> nums(n);
	rep(i,0,n) cin >> nums[i];
	sort(all(nums));
	ll resp = 0;
	rep(i,0,n){
		if(k != 0){
			ll tmp = nums[i];
			ll firstOk = tmp;
			if(tmp%x == 0){
				firstOk = tmp + (k-1)*x;
			}
			else{
				firstOk = (x-(tmp%x)) + tmp + (k-1)*x;
			}
			ll lastOk = firstOk + x;
			int idx = lower_bound(all(nums), firstOk) - nums.begin();
			int lst = lower_bound(all(nums), lastOk) - nums.begin();
			resp += (lst - idx);
		}
		else if(k == 0){
			if(nums[i]%x == 0) continue;
			ll nxt = (x - (nums[i]%x) + nums[i]);
			ll st2 = nxt - x;
			int st = lower_bound(all(nums), nums[i]) - nums.begin();
			int end = lower_bound(all(nums), nxt) - nums.begin();
			resp += (end - st);
		}
	}
	cout << resp << endl;
	return 0;
}