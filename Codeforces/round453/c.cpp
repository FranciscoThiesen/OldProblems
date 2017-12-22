/*input
2
1 1 1
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
	int pot2[20];
	pot2[0] = 1;
	rep(i, 1, 20) pot2[i] = pot2[i-1] * 2;
	init();
	int h;
	cin >> h;
	vi t(h+1);
	rep(i,0,h+1) cin >> t[i];
	bool ok = true;
	int problemPar = -1;
	int problemImpar = -1;
	// vamos ver se permanece viavel
	int prob = -1;
	for(int i = h; i > 0; --i){
		if(t[i-1] > 1 && t[i] > 1){
			ok = false;
			prob = i;
		}
	}
	if(ok) cout << "perfect" << endl;
	else{
		cout << "ambiguous" << endl;
		vi parentPrev = {1};
		vi nxt;
		cout << "0 ";
		int seen = 1;

		rep(i,1,h+1){
			for(int j = 0; j < t[i]; ++j){
				cout << parentPrev[0] << " ";
				nxt.pb(seen + j + 1);
			}
			seen += t[i];
			parentPrev = nxt;
			nxt.clear();
		}
		cout << endl;
		parentPrev = {1};
		nxt.clear();
		cout << "0 ";
		seen = 1;
		rep(i, 1, h+1){
			for(int j = 0; j < t[i]; ++j){
				if(i == prob){
					if(j == t[i] - 1){
						cout << parentPrev[0] + 1 << " ";
					}
					else cout << parentPrev[0] << " ";
				}
				else cout << parentPrev[0] << " ";
				nxt.pb(seen + j + 1);
			}
			seen += t[i];
			parentPrev = nxt;
			nxt.clear();
		}
		cout << endl;
	}

	return 0;
}

