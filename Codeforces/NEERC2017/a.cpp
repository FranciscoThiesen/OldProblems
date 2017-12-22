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
int main(){
	int n;
	ifstream in("auxiliary.in", ios::in);
	ofstream out("auxiliary.out", ios::out);
	in >> n;
	vector<ll> dp(n+1, -inf);
	vector<int> lit{2,5,5,4,5,6,3,7,6};
	dp[0] = 0;
	rep(i,2,n+1){
		rep(j,0,9){
			if(i-lit[j] >= 0){
				dp[i] = max(dp[i], dp[i-lit[j]] + j+1);
			}
		}
	}
	out << dp[n] << endl;
	return 0;
}

