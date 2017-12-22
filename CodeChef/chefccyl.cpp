/*input
1
3 3
3 1 2 2
2 1 2
3 1 4 1
2 1 2
2 1 5
3 1 3
2 1 1 2
1 1 1 2
3 1 3 3
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define mt make_tuple

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 300;

int t, n, q, k, x, y, w, n1, c1, n2, c2;


void doit(){
	scanf("%d %d", &n, &q);
	vii adjList[maxn];
	vector<vector<int> > localGraph(n, vector<int>(1, 0));
	int globalIdx = 0;
	vector<int> startNode(n); // para guardar o primeiro no de cada ciclo
	vii entradaESaida(n);
	rp(i, n){
		scanf("%d", &k); // temos k nos nesse ciclo
		startNode[i] = globalIdx + 1;
		fr(j, 1, k+1){
			scanf("%d", &w);
			//printf("Fiz uma aresta do No %d para o no %d\n", j + globalIdx, (j%k)+1+globalIdx);
			// vou comentar porque acho que isso nao eh necessario
			//adjList[j + globalIdx].pb(mp((j%k)+1+globalIdx, w));
			//adjList[(j%k)+1 + globalIdx].pb(mp(j+globalIdx, w));
			localGraph[i].pb(w); // dizendo que tem uma aresta de j para (j%k) + 1 no grafo I
		}
		globalIdx += k;
	}
	rp(i, n){
		int tam = localGraph[i].size();
		fr(j,1, tam)
		{
			localGraph[i][j] = localGraph[i][j-1] + localGraph[i][j]; // usar isso para calcular as distancias num ciclo
		}
		// como as distancias vao ser calculadas ?
		// minDist(j,k){
		// 	j e k (1, tam-1)
		// 	if(j > k) swap(j, k);
		// 	return min(localGraph[i][k] - localGraph[i][j], localGraph[i][tam-1] - localGraph[i][k] + localGrap[i][j]);
		// }
	}
	fr(i, 1, n+1){
		scanf("%d %d %d", &x, &y, &w); // aresta que vai do no i pro no (i%n) + 1
		entradaESaida[i].se = startNode[i] + (x-1);
		int j = (i%n)+1;
		entradaESaida[j].fi = startNode[j] + (y-1);
		// arestas entre ciclos, bidirecionadas
		adjList[entradaESaida[i].se].pb(mp(entradaESaida[j].fi, w));
		adjList[entradaESaida[j].fi].pb(mp(entradaESaida[i].se, w));
	}
	// criar aresta entre direta entre os nos de entrada e saida de cada ciclo
	fr(i, 1, n+1){
		if(entradaESaida[i].fi != entradaESaida[i].se){
			int a = entradaESaida[i].fi, b = entradaESaida[i].se;
			if(a > b) swap(a,b);
			int a2 = a - startNode[i] + 1;
			int b2 = b - startNode[i] + 1;
			int tam = localGraph[i].size();
			int between = min(localGraph[i][b2] - localGraph[i][a2], localGraph[i][tam-1] - localGraph[i][b2] + localGraph[i][a2]);
			// o calculo de distancia possivelmente esta certo // POSSIVELMENTE
			adjList[a].pb(mp(b, between));
			adjList[b].pb(mp(a, between));
		}
	}
	// time to start dijkstra
	vector<int> d(maxn, 1e9);
	set<ii> pq;
	d[entradaESaida[0].fi] = 0;
	pq.insert(mp(0, entradaESaida[0].fi));
	while(!pq.empty()){
		ii cur = *(pq.begin());
		pq.erase(pq.begin());
		if(d[cur.se] != cur.fi) break;
		for(const ii& p : adjList[cur.se]){
			if(d[p.fi] > cur.fi + p.se){
				if(d[p.fi] != 1e9){
					pq.erase(pq.find(mp(d[p.fi], p.fi)));
				}
				d[p.fi] = cur.fi + p.se;
				pq.insert(mp(d[p.fi], p.fi));
			}
		}
	}
	// em tese ja temos tudo que precisamos
	rp(i, q){
		scanf("%d %d %d %d", &n1, &c1, &n2, &c2);
		// sei que a distancia eh transitiva, entao posso trocar a ordem dos ciclos
		if(c1 > c2){
			swap(c1, c2);
			swap(n1, n2);
		}
		c1--;c2--;
		int d1, d2, d3, d4; // vamos deixar hardcoded os cenarios
		int tmp1, tmp2;
		int tmp3, tmp4;
		
		tmp3 = n1; tmp4 = entradaESaida[c1].fi - startNode[c1] + 1;
		if(tmp3 > tmp4) swap(tmp3, tmp4);
		int t1 =(int)localGraph[c1].size();
		int aux1 = min(localGraph[c1][tmp4] - localGraph[c1][tmp3], localGraph[c1][t1-1] - localGraph[c1][tmp4] + localGraph[c1][tmp3]);
		d1 = aux1 + dist[entradaESaida[n-1].se];  
		// there are 4 possible scenarios

	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		doit();
	}
	return 0;
}
