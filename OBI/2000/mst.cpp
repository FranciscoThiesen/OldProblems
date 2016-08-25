#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int parent[101];

int find(int x)
{
	int root = x;
	while(root != parent[root])
	{
		root = parent[root];
	}
	return root;
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if(x == y)
		return;
	parent[y] = parent[x];
}

int main()
{
	int n, e;
	int test = 1;
	while(cin >> n >> e)
	{
		if(n + e == 0)
			break;
		for(int i = 0; i < 101; ++i)
			parent[i] = i;
		vector<pair<int, pair<int, int> > > arestas;
		for(int i = 0; i < e; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			arestas.pb(mp(c, mp(a,b)));
		}
		sort(arestas.begin(), arestas.end());
		vector<pair<int, int> > mst;
		for(int j = 0; j < e; ++j)
		{
			if(find(arestas[j].second.second) != find(arestas[j].second.first))
			{

				mst.pb(mp(arestas[j].second.first, arestas[j].second.second));
				unite(arestas[j].second.first, arestas[j].second.second);
			}
		}
		printf("Teste %d\n", test);
		for(int i = 0; i < mst.size(); ++i)
			cout << min(mst[i].first, mst[i].second) << " " << max(mst[i].first, mst[i].second) << endl;
		cout << endl;
		test++;
	}
	return 0;
}