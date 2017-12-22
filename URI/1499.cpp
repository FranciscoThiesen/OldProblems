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
const int maxn = 4 * 1e4 + 5;

vector<vi> G(maxn);
vi dist(maxn);
vi dist2(maxn);
int n, m, a, b;

void bfs(int root, vi& dist){
	dist[root] = 0;
	queue<int> visit;
	visit.push(root);
	while(!visit.empty()){
		int tp = visit.front();
		visit.pop();
		for(const int& v : G[tp]){
			if(dist[v] == -1){
				dist[v] = dist[tp] + 1;
				visit.push(v);
			}
		}
	}
}

int main(){
	while(scanf("%d %d", &n, &m) == 2){
		rp(i, n) G[i].clear();
		rp(i, n-1){
			scanf("%d %d", &a, &b);
			G[--a].pb(--b);
			G[b].pb(a);
		}
		fill(all(dist), -1); // for bfs
		bfs(0, dist);
		int f = 0;
		rp(i, n) if(dist[i] >= dist[f]) f = i;
		fill(all(dist), -1);
		bfs(f,dist);
		int f2 = f;
		rp(i, n) if(dist[i] >= dist[f2]) f2 = i;
		fill(all(dist2), -1);
		bfs(f2, dist2);
		vector<int> tamanhos;
		vector<ll> somaAccu(n, 0); // cuidar dos indices 

		rp(i, n) tamanhos.pb(max(dist[i], dist2[i]));
		sort(all(tamanhos));
		somaAccu[0] = tamanhos[0];
		fr(i, 1, n) somaAccu[i] = somaAccu[i-1] + tamanhos[i];

		rp(i, m) G[i].clear();
		rp(i, m-1){
			scanf("%d %d", &a, &b);
			G[--a].pb(--b);
			G[b].pb(a);
		}
		fill(all(dist), -1);
		bfs(0, dist);
		int f3 = 0;
		rp(i, m) if( dist[i] >= dist[f3]) f3 = i;
		fill(all(dist), -1);
		bfs(f3, dist);
		int f4 = f3;
		rp(i, m) if(dist[i] >= dist[f4]) f4 = i;
		fill(all(dist2), -1);
		bfs(f4, dist2);
		vector<int> tamanho2;
		int lgst = tamanhos.back();
		int lgst2 = lgst;
		rp(i, m){
			tamanho2.pb(max(dist[i], dist2[i]));
			lgst2 = max(lgst2, max(dist[i], dist2[i]));
		}
		double accu = 0;
		for(const int& x : tamanho2){
			int idx = lower_bound(all(tamanhos), lgst2 - x - 1) - tamanhos.begin();
			if(lower_bound(all(tamanhos), lgst2 - x - 1) == tamanhos.end()){
				accu += (lgst2)*n;
			}
			else{
				if(idx == 0){
					double avg = (double)somaAccu[n-1] / (double)n;
					accu +=  (x + 1 + avg) * (n-idx);	
				}
				else{
					int qntd = n - idx; 
					double avg2 = somaAccu[n-1] - somaAccu[idx-1];
					avg2 /= qntd;
					accu += (x + 1 + avg2) * qntd ;
					accu += (lgst2) *1.0* idx;
				}
			}
		}
		accu /= (n*m);
		printf("%.3lf\n", accu);
	}	
	return 0;
}

