/*input
1
4
1 1 1 1
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(v) (v).begin, (v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define sz(a) static_cast<int>(a.size())
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 51;

ll state[MAXN][MAXN][MAXN];
vi vec(MAXN);

map<vi, ll> memo;

int t, n, x;

ll go(int i, int e1, int e2){
	printf("(i, e1, e2) = (%d, %d, %d)\n", i, e1, e2);
	if(state[i][e1][e2] != -1) return state[i][e1][e2];	
	ll rsp = 1;
	rp(k, min(e1,e2)+1){
		int aux = 0;
		if(i+2 < n){
			aux = vec[i+2];
		}
		rsp += go(i+1, e2-k, aux+k);
	}
	return state[i][e1][e2] = rsp % MOD;
}
main(){	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(state, -1, sizeof state);
		rp(i, n){
			scanf("%d", &vec[i]);
		}
		
		cout << go(0, vec[0], vec[1]) << endl;
		
	}
}
