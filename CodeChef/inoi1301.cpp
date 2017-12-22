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
 
const int N = 1e6 + 13;
int n, k;
ll a[N], dp[2][N];
 
int main(){
	scanf("%d %d", &n, &k);
	rep(i,0,n) scanf("%lld", &a[i]);
	k--;
	dp[0][k] = 0;
	rep(i, k+1, n){
		if(i - 2 >= k) dp[0][i] = max(dp[0][i-1], dp[0][i-2]) + a[i];
		else dp[0][i] = dp[0][i-1] + a[i];
	}
	dp[1][0] = 0; // melhor custo que podemos ter indo de j ate 0
	rep(i, 1, n){
		if(i == 1) dp[1][i] = dp[1][i-1] + a[i-1];
		else dp[1][i] = max(dp[1][i-1] + a[i-1], dp[1][i-2] + a[i-2]);
	}
	ll best = neginf;
	rep(i, k, n){
		if(i == 0) best = max(best, dp[0][i]);
		else best = max(best, dp[0][i] + dp[1][i]);
	}
	printf("%lld\n", best);
	return 0;
}
 
