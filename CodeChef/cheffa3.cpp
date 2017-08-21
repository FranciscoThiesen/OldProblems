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
 
map<vi, ll> memo;
 
int t, n, x;
 
ll go(vi& s){
	if(memo[s]) return 0;
	ll resp = 1;
	int tam = sz(s)-1;
	rp(i, tam){
		if(i+1 == tam){
			if(s[i] && s[i+1]){
				vi cpy = s;
				cpy[i]--; cpy[i+1]--; cpy.pb(1);
				resp = (resp + go(cpy)) % MOD;
			}
		}else{
			if(s[i] && s[i+1]){
				vi cp = s;
				cp[i]--; cp[i+1]--; cp[i+2]++;
				resp = (resp + go(cp)) % MOD;
			}
		}
	}
	return memo[s] = resp;
}
 
main(){	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vi vec(n);
		rp(i, n){
			scanf("%d", &vec[i]);
		}
		printf("%lld\n", go(vec));
		for(const auto& state : memo){
            for(const int& i : state.fi){
                printf("%d ", i);
            }
            puts("");
        }
        memo.clear();
	}
}
