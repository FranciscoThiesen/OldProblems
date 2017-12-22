/*input
9
ab??ab???
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

int n, m;
string s;
int tam;

int calculateCost(int stPos){
	if(tam - stPos < m) return -1;
	int cost = 0;
	rep(i, 0, m){
		if(i%2){
			if(s[stPos+i] == 'a') return -1;
			if(s[stPos+i] == '?') cost++;
		}
		else{
			if(s[stPos+i] == 'b') return -1;
			if(s[stPos+i] == '?') cost++;
		}
	}
	return cost;
}

int main(){
	init();
	cin >> n;
	cin >> s;
	cin >> m;
	tam = SZ(s);
	cout << n << " " << m << endl;
	vector<ii> item;
	rep(i,0,tam){
		if(s[i] == 'a' || s[i] == '?'){
			int x = calculateCost(i);
			if(x != -1){
				item.pb(mp(i, x));
			}
		}
	}
	if(item.empty()){
		cout << 0 << endl;
		return 0;
	}
	int t = SZ(item);
	vector<ii> dp(t, mp(0, inf));
	dp[0] = mp(1, item[0].se);
	rep(i, 1, t){
		int idx = item[i].fi;
		int queroUsar = lower_bound(all(item), mp(idx-m+1, -1)) - item.begin() - 1;
		if(queroUsar == -1){
			dp[i] = dp[i-1];
			if(dp[i].fi == 1){
				dp[i].se = min(dp[i].se, item[i].se);
			}
		}
		else{
			int talvez = 1 + dp[queroUsar].fi;
			int gasto = dp[queroUsar].se + item[i].se;
			int opt = dp[i-1].fi;
			int gasto2 = dp[i-1].se;
			if(talvez == opt){
				dp[i] = mp(talvez, min(gasto, gasto2));
			}
			else if(talvez > opt){
				dp[i] = mp(talvez, gasto);
			}
			else dp[i] = dp[i-1];
		}
	}
	cout << dp[t-1].se << endl;
	return 0;
}

