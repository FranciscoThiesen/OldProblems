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
const int maxn = 101;

int m, n, q, a, b, w;
vector<ii> adjList[maxn];

int main(){
	while(scanf("%d %d", &n, &m) == 2){
		if(!(n+m)) break;
		rp(i, n+1) adjList[i].clear();
		rp(i, m){
			scanf("%d %d %d", &a, &b, &w);
			adjList[a].pb(mp(w,b));
			adjList[b].pb(mp(w,a));
		}
		scanf("%d", &q);
		rp(i, q){
			scanf("%d %d", &a, &b);
			set<tuple<int, int, int> > pq;
			vector<int> dist(n+1, inf);
			vector<int> minUsed(n+1, 0);
			dist[a] = 0;
			minUsed[a] = 0;
			pq.insert(mt(0, 0, a));
			while(!pq.empty()){
				int dst, minV, node;
				tie(dst, minV, node) = *(pq.begin());
				pq.erase(pq.begin());
				for(const ii& dupla : adjList[node]){
					if(dst + dupla.fi < dist[dupla.se]){
						if(dist[dupla.se] != inf){
							pq.erase(pq.find(mt(dist[dupla.se], minUsed[dupla.se], dupla.se)));
						}
						dist[dupla.se] = dst + dupla.fi;
						minUsed[dupla.se] = max(minV, dupla.fi);
						pq.insert(mt(dist[dupla.se], max(minV, dupla.fi), dupla.se));
					}
					else if(dst + dupla.fi == dist[dupla.se]){
						if(max(minV, dupla.fi) < minUsed[dupla.se]){
							minUsed[dupla.se] = max(minV, dupla.fi);
							pq.insert(mt(dist[dupla.se], minUsed[dupla.se], dupla.se));
						}
					}
				}
			}
			printf("O menor caminho de %d ate %d = %d\n", a, b, dist[b]);
			printf("%d\n", minUsed[b]);
		}
	}
	return 0;
}

