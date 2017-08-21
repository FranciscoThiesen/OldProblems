#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int tot = 0;
	int need = k;
	bool ok = true;
	rp(i, n){
		int x;
		scanf("%d", &x);
		tot += x;
		int rem = min(need, min(tot, 8));
		tot -= rem;
		need -= rem;
		if(!need){
			printf("%d\n", i+1);
			ok = false;
			break;
		}
	}
	if(ok)puts("-1");
}
