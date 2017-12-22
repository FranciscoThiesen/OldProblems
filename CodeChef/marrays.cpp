#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())
 
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int limit = 1000001;
 
//ll dp[limit][2];
 
ll dp[limit][2];
int vec[limit];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		
		int n;
		cin >> n;
		vector<ii> allRot[n];
		int k;
		int mxFi = -1, minFi = 1e9;
		int mxSe = -1, minSe = 1e9;
		cin >> k;
		rp(j, k){
			cin >> vec[j];
			mxFi = max(mxFi, vec[j]);
			minFi = min(minFi, vec[j]);
		}
		allRot[0].pb(mp(vec[0], vec[k-1]));
		fr(q, 0, k-1){
			allRot[0].pb(mp(vec[q+1], vec[q]));
		}
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		cin >> k;
		rp(j, k){
			cin >> vec[j];
			mxSe = max(mxSe, vec[j]);
			minSe = min(minSe, vec[j]);
		}
		allRot[1].pb(mp(vec[0], vec[k-1]));
		fr(q, 0, k-1){
			allRot[1].pb(mp(vec[q+1], vec[q]));
		}
		fr(i,2, n){
			cin >> k;
			rp(j, k){
				cin >> vec[j];
			}
			allRot[i].pb(mp(vec[0], vec[k-1]));
			fr(q, 0, k-1){
				allRot[i].pb(mp(vec[q+1], vec[q]));
			}
		}
		int resp;
		if(n == 2){
			resp = max(abs(mxFi - minSe), abs(maxSe - minFi));
			cout << resp << endl;
			continue;
		}
		

		memset(dp, 0ll, sizeof dp);
		unordered_set<int> prev;
		ll ans = 0;
		for(const ii& x : allRot[0]){
			prev.insert(x.se);
		}
		fr(i,1,n){
			unordered_set<int> nxt;
			for(const ii& x : allRot[i]){
				for(const int& v : prev){
					dp[x.se][i%2] = max(dp[x.se][i%2], dp[v][(i-1)%2] + 1ll*abs(v - x.fi) * i);
				}
				nxt.insert(x.se);	
			}	
			prev = nxt;
		}
		int idx = (n-1)%2;
		for(const int& v : prev) ans = max(ans, dp[v][idx]);
		cout << ans << endl;
	}
	return 0;
} 