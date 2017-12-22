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

const int inf = 600000;
const int neginf = 0xc0c0c0c0;
const int maxn = 101;
int n, m, a, b, w, q;
int dist[maxn];
int floyd[maxn][maxn];
vector<tuple<int, int, int> > edges;

int query(int a, int b){
	dist[a] = 0;
	rp(i, floyd[a][b]){
		for(const tuple<int, int, int>& e : edges){
			if(dist[get<0>(e)] + get<2>(e) < dist[get<1>(e)]){
				dist[get<1>(e)] = dist[get<0>(e)] + get<2>(e);
			}
		}
	}
	return dist[b];
}

void fw(){
	rp(i, n+1){
		rp(j, n+1){
			if(i == j) floyd[i][i] = 0;
			else floyd[i][j] = inf;
		}
	}
	rp(z, n){
		rp(x, n){
			rp(y, n){
				floyd[x][z] = min(floyd[x][y] + floyd[y][z], floyd[x][z]);	
			}
		}
	}
}

int main(){
	while(scanf("%d %d", &n, &m) == 2){
		if(!(n+m))break;
		edges.clear();
		memset(floyd, inf, sizeof floyd);
		rp(i, n+1) floyd[i][i] = 0;
		rp(i, m){
			scanf("%d %d %d", &a, &b, &w);
			edges.pb(mt(a,b,-w));
			floyd[a][b] = floyd[b][a] = 1;
		}
		fw();
		scanf("%d", &q);
		
		rp(i, q){
			scanf("%d %d", &a, &b);
			printf("%d\n", -query(a,b));
		}
	}
	return 0;
}

