#include <bits/stdc++.h>
using namespace std;

int parent[50001];


void initialize()
{
	for(int i = 0; i < 50001;++i)
		parent[i] = i;
}

int find_parent(int x)
{
	while(x != parent[x])
	{
		x = parent[x];
	}
	return parent[x];
}

void unite(int x, int y)
{
	int px = find_parent(x);
	int py = find_parent(y);
	parent[px] = py;
}

int main()
{
	int n, e;
	cin >> n >> e;
	while(n + e != 0)
	{
		initialize();
		vector<tuple<int, int, int> > edges;
		unsigned int ans = 0;
		for(int i = 0; i < e; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back(make_tuple(z, x, y));
		}
		sort(edges.begin(), edges.end());
		for(auto& p : edges)
		{
			if(find_parent(get<1>(p)) != find_parent(get<2>(p)))
			{
				ans += get<0>(p);
				unite(get<1>(p), get<2>(p));
			}
		}
		cout << ans << endl;
		cin >> n >> e;
	}
}
