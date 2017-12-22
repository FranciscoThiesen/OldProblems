/*input
3
0 2 1
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
const int maxn = 1e5 + 5;
int arr[maxn];
vector<bool> ok(maxn, false);
vector<int> melhora(maxn, 0);
int maiorVisto = -1;
set<int> elem;
int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n)scanf("%d", &arr[i]);
	if(n == 1){
		printf("%d\n", arr[0]);
		return 0;
	}
	ok[0] = true;
	maiorVisto = max(maiorVisto, arr[0]);
	melhora[arr[0]] = -1;
	elem.insert(arr[0]);
	rep(i,1,n){
		if(elem.upper_bound(arr[i]) == elem.end()){
			ok[i] = true;
			melhora[arr[i]] -= 1;
		}
		else{
			auto it = elem.upper_bound(arr[i]);
			if(*it == maiorVisto){
				melhora[*it] += 1;
			}
		}
		elem.insert(arr[i]);
		maiorVisto = max(maiorVisto, arr[i]);
	}
	int melhor = arr[0];
	int best = melhora[arr[0]];
	rep(i,1,n){
		if(melhora[arr[i]] > best){
			best = melhora[arr[i]];
			melhor = arr[i];
		}
		else if(melhora[arr[i]] == best){
			melhor = min(arr[i], melhor);
		}
	}
	printf("%d\n", melhor);
	return 0;
}