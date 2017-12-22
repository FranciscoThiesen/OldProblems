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
const int maxn = 1e6 + 5;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }
ll ans[maxn];
ll accuSum[2*maxn];

int calc(int digs){
	string x = to_string(digs);
	int e = 0, o = 0;
	for(const char& c : x){
		int dig = c-'0';
		if(dig%2)o+=dig;
		else e+= dig;
	}
	return abs(e-o);
}


int main(){
	init();
	int t;
	cin >> t;
	ans[1] = 2;
	ans[2] = 12;
	rep(i, 4, 2*maxn){
		accuSum[i] = accuSum[i-1] + calc(i);
	}
	rep(i, 3, 1e6 + 1){
		// prev is odd
		ans[i] = ans[i-1];
		int st = i+1;
		int nd = 2*i - 2;
		ans[i] += (accuSum[nd] - accuSum[st-1])*2;
		ans[i] += calc(i+i) + 2*(calc(i+i-1));

	}
	rep(i,0,t){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}

