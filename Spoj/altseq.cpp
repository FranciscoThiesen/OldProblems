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

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

const int maxn = 5013;
int n, arr[maxn], dp[maxn];



bool ok(int i, int j){
	if(1ll * ((ll)arr[i]) * ((ll)arr[j]) < 0ll){
		return (abs(arr[i]) > abs(arr[j]));
	}
	return false;
}

int main(){
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", arr + i);
	dp[0] = 1;
	int best = 1;
	rep(i, 1, n){
		dp[i] = 1;
		for(int j = i-1; j >= 0; --j){
			if(ok(i, j)){
				dp[i] = max(dp[i], dp[j] + 1);
				best = max(best, dp[i]);
			}
		}
	}
	printf("%d\n", best);
	return 0;
}

