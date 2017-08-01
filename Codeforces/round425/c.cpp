
 #include <bits/stdc++.h>
#include <cmath>
#include <string.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define max3(A,B,C) max((A),max((B),(C)))
#define lb lower_bound
#define ub upper_bound
#define up(A) ((A) >= 'A' && (A) <= 'Z')
#define upc(A) ((A) + (!up(A))*('A' - 'a'))

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<pair<int,int> > vii;

const double PI = 4.0*atan(1.0);
const ll N = 0;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 50;
const int LOGMAX = 20;

int vd[MAXN][LOGMAX], dad[MAXN], mrc[MAXN];
vi v[MAXN];

void dfs(int a, int pai, int lvl) {
	mrc[a] = lvl;
	dad[a] = pai;
	for(int i = 0; i < v[a].size(); i++) if(mrc[v[a][i]] == 0) dfs(v[a][i], a, lvl + 1);
}

void build(int n) {
	for(int i = 0; i < n; i++) vd[i][0] = dad[i];
	for(int j = 1; j < LOGMAX; j++) {
		for(int i = 0; i < n; i++) {
			vd[i][j] = vd[vd[i][j-1]][j-1];
		}
	}
}

int dist(int a, int b) {
	int d = 0;
	if(mrc[a] > mrc[b]) swap(a, b);
	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(mrc[vd[b][i]] > mrc[a]) {
			b = vd[b][i];
			d += 1 << i;
		}
	}
	if(mrc[b] != mrc[a]) {
		d++;
		b = vd[b][0];
	}

	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(vd[b][i] != vd[a][i]) {
			a = vd[a][i];
			b = vd[b][i];
			d += 2*(1 << i);
		}
	}
	if(b != a) d += 2;
	return d;
}

int main() {
   int n, q, x;
   scanf("%d %d", &n, &q);
   for(int i = 0; i < n - 1; i++) {
      scanf("%d", &x);
      v[x-1].pb(i+1);
      v[i+1].pb(x-1);
   }
   memset(mrc,0,sizeof(int)*n);

   dfs(0, 0, 1);
   build(n);

   int a, b, c;
   while(q--) {
      scanf("%d %d %d", &a, &b, &c);
      a--;
      b--;
      c--;
      int ans = 0;
      if(a == b) ans = dist(a, c);
      else if(a == c) ans = dist(a, b);
      else if(c == b) ans = dist(a, b);
      else {
         int ab = dist(a, b);
         int ac = dist(a, c);
         int bc = dist(b, c);
         ans = max3(ab + bc - ac, ab + ac - bc, ac + bc - ab)/2;
      }
      printf("%d\n", ans + 1);
   }

   return 0;
}