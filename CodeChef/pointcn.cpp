/*input
1
4 10 20
123456789012 4567890123456
11111111111111 2222222222222
101010101010 2323232323232
112358132134 1928374655647
999999555555 5555559999999
234123124155 1241352352345
234213515123 1231245551223
523432523332 1234124515123
*/
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

unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

struct UF{
	int N;
	vi parent, rk;
	UF(int _N){
		int N = _N;
		rk.assign(N, 0);
		parent.resize(N);
		iota(all(parent), 0);
	}

	int find(int node){
		if(parent[node] != node){
			parent[node] = find(parent[node]);
		}
		return parent[node];
	}

	bool unite(int x, int y){
		int a = find(x), b = find(y);
		if(a == b) return false;
		if(rk[a] < rk[b]) swap(a,b);
		parent[b] = a;
		if(rk[a] == rk[b])rk[a]++;
		return true;
	}

};

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

vector<ii> ans;
ll best;

void attempt(int n){
	//unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, n-1);
	vector<ii> edg;
	int adjMat[n][n] = {{0}};
	vector<int> degree(n, 0);
	ll cost = 0;
	int edges = 0;
	UF uniao(n);
	while( edges != n-1){
		int a = dis(gen), b = dis(gen);
		bool ok = uniao.unite(a, b);
		if(ok){
			adjMat[a][b] = adjMat[b][a] = 1;
			edg.pb(mp(a,b));
			cost += C[a][b];
			degree[a]++;
			degree[b]++;
			edges++;
		}
	}
	int rd1 = dis(gen);
	rp(i, rd1 * 10){
		int a = dis(gen), b = dis(gen);
		if(a == b) continue;
		if(!adjMat[a][b]){
			adjMat[a][b] = adjMat[b][a] = 1;
			edg.pb(mp(a,b));
			cost += C[a][b];
			degree[a]++;degree[b]++;
		}
	}
	rp(i, n){
		cost += H[i][degree[i]];
	}
	if(cost < best){
		ans = edg;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		best = (Cmax + Hmax) * 10000000;
		int R[MX][MX] = {{0}};
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}

		rp(i, 1000){
			attempt(n);
		}
		for(const ii& x : ans){
			R[x.fi][x.se] = R[x.se][x.fi] = 1;
		}
		rp(i, n){
			rp(j, n){
				if(R[i][j]) printf("1");
				else printf("0");
			}
			puts("");
		}
	}	
	return 0;
}
