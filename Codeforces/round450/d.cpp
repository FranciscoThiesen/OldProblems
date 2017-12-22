/*input
3
1 2
2 1
4 60
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
	int l = 0, r = 0;
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > 0) r++;
		else l++;
	}
	if(r == 0 || l == 0){
		printf("Yes\n");
	}
	else if(r == 1 || l == 1){
		printf("Yes\n");
	}
	else printf("No\n");
	return 0;
}

