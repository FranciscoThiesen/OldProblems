/*input
5
1 2 17 3 5
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
const int maxn = 2*1e5 + 5;
int arr[maxn];
vector<bool> ok(maxn, false);
vector<int> melhora(maxn, 0);
int maiorVisto = -1;
int qntMaior = 1;

set<ii> elem;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n)scanf("%d", &arr[i]);
	if(n == 1){
		printf("%d\n", 0);
		return 0;
	}
	ok[0] = true;
	maiorVisto = max(maiorVisto, arr[0]);
	melhora[0] = -1; // temos que mudar melhora[i] pra indice
	elem.insert(mp(arr[0]+1,0));
	int count = 1;
	rep(i,1,n){
		if(elem.lower_bound(mp(arr[i], i)) == elem.end()){
			ok[i] = true;
			count++;
			melhora[i] -= 1;
			//cout << "achei um cara valido" << endl;
			//cout << arr[i] << " " << i << endl;
		}
		else{
			auto it = elem.lower_bound(mp(arr[i], i));
			if((*it).fi - 1 == maiorVisto && qntMaior == 1){
				melhora[(*it).se] += 1;
			}
		}
		elem.insert(mp(arr[i] + 1, i));
		if(arr[i] == maiorVisto) qntMaior++;
		else if(arr[i] > maiorVisto){
			qntMaior = 1;
			maiorVisto = arr[i];
		}
		//maiorVisto = max(maiorVisto, arr[i]);
	}
	int melhor = arr[0];
	int best = melhora[0];
	rep(i,1,n){
		if(melhora[i] > best){
			best = melhora[i];
		}
	}
	printf("%d\n", count + best);
	return 0;
}