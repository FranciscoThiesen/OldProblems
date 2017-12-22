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
const int N = 6 * 1e3 + 13;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

int t;
string s;

int dp[N][N];

int main(){
	init();
	cin >> t;
	rep(i,0,t){
		cin >> s;
		int tam = SZ(s);
		memset(dp,0,sizeof dp);
		rep(i,0,tam) dp[i][i] = 0;
		rep(comp, 1, tam){
			rep(start, 0, tam - comp){
				if(s[start] == s[start + comp]){
					if(comp == 1){
						dp[start][start + comp] = 0;
					}
					else dp[start][start+comp] = dp[start+1][start+comp-1];
				}
				else{
					dp[start][start+comp] = min(dp[start+1][start+comp], dp[start][start+comp-1]) + 1;	
				}
			}
		}
		cout << dp[0][tam-1] << endl;
	}
	return 0;
}

