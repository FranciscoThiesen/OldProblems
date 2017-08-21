/*input
3
3
2 3 1
2
2 2
3
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 150;

int n, t, vec[MAXN], state[MAXN][MAXN][MAXN];

int solve(int i, int j, int k){
	int ret = 0;

	if( k == 0 && i >= n-1) return state[i][j][k] = 1;
	if(state[i][j][k] != -1) return state[i][j][k];

	rp(l, min(j, k) + 1)
		ret = (ret + solve(i+1, k-l, vec[i+2] + l) )%MOD;
	
	return state[i][j][k] = ret % MOD;
}

main(){
	scanf("%d", &t);
	while(t--){
		memset(state, -1 ,sizeof state);
		memset(vec, 0, sizeof vec);
		scanf("%d", &n);
		rp(i, n) scanf("%d", &vec[i]);
		printf("%d\n", solve(0,vec[0],vec[1]));
	}
}
