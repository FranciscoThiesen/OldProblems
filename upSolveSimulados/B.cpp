/*input
8 3 169 169 1
0 3 5
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)

typedef vector<int> vi;
typedef pair<int, int> ii;
const int maxn = 1e6 + 10;

int main(){
	int n, t, a, x, y, k;
	scanf("%d %d %d %d %d", &n, &t, &a, &x, &y);
	int msk = 1;
	int seen[maxn];
	rp(i, t){
		scanf("%d", &k);
		msk |= (1 << k);
	}
	memset(seen, -1, sizeof seen);
	int cur = a%x;
	seen[0] = 0;
	for(int i = 1;;i++){
		if(seen[cur] == -1) seen[cur] = i;
		else if(i - seen[cur] >= y){
			printf("%d %d\n", seen[cur], i-1);
			break;
		}
		a = ((__builtin_popcount(a & msk) & 1) << (n-1) ) | (a >> 1);
		cur = (cur + a)%x;
	}
	return 0;
}