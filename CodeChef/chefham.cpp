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
const int maxn = 1e5 + 5;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }


void solve(vi& orig){
	int bestDiff = 0;
	vi tmp = orig;
	vi ans;
	sort(all(tmp));
	int sz = SZ(orig);
	do{
		int cur = 0;
		rep(i,0,sz)cur += (orig[i] != tmp[i])? 1 : 0;
		if(cur >= bestDiff){
			bestDiff = cur;
			ans = tmp;
		}		
	}while(next_permutation(all(tmp)));
	cout << bestDiff << endl;
	for(const int& v : ans) cout << v << " ";
	cout << endl;
}

int main(){
	init();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vi cpy(n);
		vi nums(n);
		int freq[maxn];
		memset(freq, 0, sizeof freq);
		int occur[maxn][2];
		vector<ii> dup;
		rep(i,0,n){
			cin >> nums[i];
			freq[nums[i]]++;
			if(freq[nums[i]] == 2) occur[nums[i]][1] = i;
			else occur[nums[i]][0] = i;
		}
		if(n < 5){
			solve(nums);
			continue;
		}
		bool ok = true;
		rep(i,0,maxn){
			if(freq[i] == 2){
				dup.pb(mp(i, occur[i][0]));
				dup.pb(mp(i, occur[i][1]));
				ok = false;
			}
		}
		rep(i,0,maxn){
			if(freq[i] == 1){
				dup.pb(mp(i, occur[i][0]));
			}
		}
		if(ok){
			cout << n << endl;
			rotate(nums.begin(), nums.begin() + 1, nums.end());
			for(int& v : nums)cout << v << " ";
			continue;
		}	
		int ans = 0;
		rep(i,0,n){
			cpy[dup[(i+2)%n].se] = dup[i].fi;
		}
		rep(i, 0, n) if(cpy[i] != nums[i])ans++;
		cout << ans << endl;
		for(const int& v : cpy){
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}

