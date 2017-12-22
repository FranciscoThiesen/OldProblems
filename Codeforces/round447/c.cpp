/*input
4
1 2 8 12
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
const int maxn = 1010;
int arr[maxn];

int main(){
	init();
	int n;
	cin >> n;
	vi arr(n);
	rep(i,0,n) cin >> arr[i];	
	sort(all(arr));
	int gcd = arr[0];
	rep(i,1,n) gcd = __gcd(gcd, arr[i]);
	if(arr[0] != gcd){
		cout << -1 << endl;
		return 0;
	}
	set<int> teste;
	cout << n << endl;
	rep(i, 0, n){
		cout << arr[i] << " ";
	}
	cout << endl;
	// rep(i, 0, n){
	// 	int st = arr[i];
	// 	teste.insert(st);
	// 	rep(j, i+1, n){
	// 		st = __gcd(st, arr[j]);
	// 		teste.insert(st);
	// 	}
	// }
	return 0;
}

