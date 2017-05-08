#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAXN 50001
#define fi first
#define se second

vector<vector<ii> > adjList;
vector<int> dist;
vector<bool> visited;

unordered_set<int> selected;

vector<ii> rootSon;

pair<int, int> calcula_distancia_media(int root)//retorna soma de distancias de desc e qntd de desc
{
	int soma_dist_desc = 0;
	int numDesc = 0;
	visited[root] = 1;
	for(auto& p : adjList[root])
	{
		if(visited[p.second] == 0)// eh filho e nao foi visitado
		{
			pair<int, int> k = calcula_distancia_media(p.second);
			if(selected.find(p.second) != selected.end())
			{	
				numDesc += k.first + 1;
				soma_dist_desc += k.first + (p.second*k.second) + p.first;
				if(root == 0)
				{
					rootSon.pb(mp(k.first + 1, k.first + (p.second*k.second) + p.first));
				}
			}
		}
	}
	return mp(soma_dist_desc, numDesc);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		double ans = 0;
		int nodes, select;
		cin >> nodes >> select;
		adjList.resize(nodes);
		visited.resize(nodes);
		fill(visited.begin(), visited.end(), 0);

		// ler arestas do grafo
		for(int i = 0; i < nodes-1; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			adjList[x-1].pb(mp(z, y-1));
			adjList[y-1].pb(mp(z, x-1));
		}

		//ler os elementos que estao na lista para serem selecionados
		for(int i = 0; i < select; ++i)
		{
			int g;
			cin >> g;
			selected.insert(g);
		}

		//escolher um no como raiz arbitraria
		int root = 0;
		ii resp = calcula_distancia_media(root);
		cout << (float)resp.fi/resp.se << endl;
		adjList.clear();
		selected.clear();
	}
	return 0;
}