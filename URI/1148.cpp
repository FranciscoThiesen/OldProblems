#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> pii;

vector<bool> globalVisited(500, false);

const int INF = 1000 * 1000 * 1000;
vector<int> findSCC(int root, vector<vector<int> > adjList, vector<vector<int> > reverseAdjList)
{
	int sz = adjList.size();
	vector<bool> visited(sz, false);
	vector<bool> visited2(sz, false);

	queue<int> fila;
	fila.push(root);
	visited[root] = true;
	visited2[root] = true;
	while(!fila.empty())
	{
		int a = fila.back();
		fila.pop();
		for(auto& p : adjList[a])
		{
			if(visited[p] == false)
			{
				visited[p] = true;
				fila.push(p);
			}
		}
	}
	fila.push(root);
	while(!fila.empty())
	{
		int b = fila.back();
		fila.pop();
		for(auto& p : reverseAdjList[b])
		{
			if(visited2[p] == false)
			{
				visited2[p] = true;
				fila.push(p);
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < sz; ++i)
	{
		if(visited[i] && visited2[i])
			ans.pb(i);
	}
	return ans;
}
int main()
{
	int n, e;
	cin >> n >> e;
	while(n+e != 0)
	{
		//cout << n << " " << e << endl;
		vector<vector<int> > adjList(n);
		vector<vector<int> > revAdjList(n);
		vector<tuple<int, int, int> > edges;
		int adjMat[500][500];
		memset(adjMat, -1, sizeof(adjMat));
		for(int i = 0; i < e; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			adjList[x-1].push_back(y-1);
			revAdjList[y-1].push_back(x-1);
			edges.push_back(make_tuple(x-1, y-1, z));
		}
		for(int i = 0; i < n; ++i)
		{
			if(!globalVisited[i])
			{	
				globalVisited[i] = true;
				vector<int> tmp = findSCC(i, adjList, revAdjList);
				for(int i = 0; i < tmp.size(); ++i)
				{	
					globalVisited[tmp[i]] = true;
					for(int j = i + 1; j < tmp.size(); ++j)
					{
						adjMat[tmp[i]][tmp[j]] = 0;
						adjMat[tmp[j]][tmp[i]] = 0;
					}
				}
			}
		}
		for(auto& p : edges)
		{
			int g,h,i;
			tie(g,h,i) = p;
			if(adjMat[g][h] == -1)
				adjMat[g][h] = i;
		}
		// dealing with queries

		int q;
		cin >> q;
		//cout << "queries : " <<  q << endl;
		for(int i = 0; i < q; ++i)
		{
			int s, t;
			cin >> s >> t;
			s--;
			t--;
			set<pii> fila;
			vector<int> dist(n, INF);
			fila.insert(mp(0, s));
			dist[s] = 0;
			while(!fila.empty())
			{
				pii tmp = *(fila.begin());
				fila.erase(fila.begin());

				int u = tmp.se;

				for(int i = 0; i < n; ++i)
				{
					if(adjMat[u][i] != -1)
					{
						if(dist[i] > dist[u] + adjMat[u][i])
						{
							if(dist[i] != INF)
								fila.erase(fila.find(make_pair(dist[i], i)));
						

							dist[i] = dist[u] + adjMat[u][i];
							fila.insert(mp(dist[i], i));
						}
					}
				}
			}
			if(dist[t] == INF)
				cout << "Nao e possivel entregar a carta" << endl;
			else
				cout << dist[t] << endl;
		}
		cout << endl;
		fill(globalVisited.begin(), globalVisited.end(), false);
		cin >> n >> e;
	}
	return 0;
}
