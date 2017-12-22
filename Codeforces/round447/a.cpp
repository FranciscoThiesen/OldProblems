/*input
QAQQQZZYNOIWIN
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
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
	init();
	string s;
	cin >> s;
	int n = SZ(s);
	int resp = 0;
	rep(i, 0, n){
		for(int j = n-1; j >= i+1; --j){
			if(s[j] == 'Q' && s[i] == 'Q'){
				for(int k = i+1; k < j; ++k){
					if(s[k] == 'A'){
						resp++;
					}
				}
			}
		}
	}
	cout << resp << endl;
	return 0;
}

