/*input
2
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
	init();
	int n;
	cin >> n;
	if(n == 1){
		cout << "1\n0 1\n0\n1" << endl;
		return 0;
	}
	cout << n << endl;
	rep(i,0,n+1) cout << ((i%2)? 1 : -1) << " ";
	cout << endl;
	//cout << 1 << endl;
	cout << n-1 << endl;
	rep(i,0,n-1) cout << ((i%2)? 1 : -1) << " ";
	cout << 0 << endl;
	cout << endl;
	return 0;
}

