/*input
4
1 1
1 1
1 1
1 1
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
int arr[2][40];
int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n)scanf("%d %d", &arr[0][i], &arr[1][i]);
	int count = 0;
	int best = inf;
	vi ans;
	while(count < 100010){
		vector<int> tot(n, 0);
		rep(t, n/2, n-1){
			rep(k, 0, t) tot[k] = 1;
		
			rep(i,0,1000){
				count++;
				random_shuffle(all(tot));
				ll s1 = 0, s2 = 0;
				rep(x, 0, n){
					if(tot[i])s2 += arr[1][i];
					else s1 += arr[0][i];
				}
				if(s1 == s2){
					if(t < best){
						ans = tot;
					}
				}
			}
		}
	}
	if(best != inf) for(const int& v : ans) cout << v;
	cout << endl;
	return 0;
}

