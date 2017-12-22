/*input
5 1 2 3
1 2 3 4 5
*/
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

int main(){
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	vector<ll> vec(n);
	rp(i, n){
		cin >> vec[i];
	}
	ll dp[4][n];
	rp(i, 4){
		rp(j, n){
			dp[i][j] = 0ll;
		}
	}
	dp[2][n-1] = r * vec[n-1];
	dp[1][n-1] = dp[2][n-1] + q*vec[n-1];
	dp[0][n-1] = dp[1][n-1] + p * vec[n-1];
	ll v[3];
	v[0] = p;
	v[1] = q;
	v[2] = r;
	for(int i = 2; i >= 0; --i){
		for(int idx = n-2; idx >= 0; --idx){
			dp[i][idx] = max(dp[i][idx+1], vec[idx]*v[i] + dp[i+1][idx]);
		}
	}
	ll best = dp[0][0];
	rp(i, n) best = max(best, dp[0][i]);

	cout << best << endl;
	return 0;
}

