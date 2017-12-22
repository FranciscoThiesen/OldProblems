/*input
2
1 2 3 10 1 5
2 2 1 1 2 3
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

int t, a, b, c, x, y, z;

unordered_map<tuple<int, int, int>, int> explore;

int main(){
	scanf("%d", &t);
	rep(i,0,t){
		scanf("%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
		explore.clear();
		multimap<int, tuple<int, int, int> > q;
		explore[mt(0,0,0)] = 0;
		q[0] = mt(0,0,0);
		while(!q.empty()){
			auto topo = *(q.begin());
			q.erase(q.begin());
			
		}
	}
}
