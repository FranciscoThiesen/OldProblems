/*input
aaaaa
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
const int maxn = 1005;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }
ll dp[maxn][maxn][26];

int main(){
	init();
	string s;
	cin >> s;
	int sz = SZ(s);
	s = "$" + s;
	for(int l = sz; l>= 1; --l){
		rep(r, l, sz+1){
			rep(alpha, 0, 26){
				if(l == r && s[l]-'a' == alpha){
					dp[l][r][alpha] = 1;
				}
				else if(s[l] - 'a' != alpha || s[r] - 'a' != alpha){
					dp[l][r][alpha] = dp[l+1][r][alpha] + dp[l][r-1][alpha] - dp[l+1][r-1][alpha];
					dp[l][r][alpha] %= mod;
				}
				else if(s[l] == s[r] && s[l] - 'a' == alpha){
					dp[l][r][alpha] = 2;
					rep(x, 0, 26){
						dp[l][r][alpha] += dp[l+1][r-1][x];
						dp[l][r][alpha] %= mod;
					}
				}
			}
		}
	}
	ll ans = 0;
	rep(x, 0, 26){
		ans += dp[1][sz][x];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

