#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
int parent[500];

void initialize()
{
	for(int i = 0; i < 500; ++i)
	{
		parent[i] = i;
	}
}

int find_parent(int x)
{
	while(x != parent[x])
	{
		x = parent[x];
	}
	return x;
}

void unite(int x, int y)
{
	parent[find_parent(x)] = find_parent(y);
}

double dist(int x1, int x2, int y1, int y2)
{
	double a = abs((double)x1-x2);
	double b = abs((double)y1-y2);
	return sqrt(a*a + b*b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		initialize();
		int n;
		cin >> n;
		vector<pair<int, int> > coord(n);
		for(int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			coord[i] = make_pair(x, y);
		}
		vector<tuple<double, int, int> > edges;
		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				edges.push_back(make_tuple(dist(coord[i].fi, coord[j].fi, coord[i].se, coord[j].se), i, j));
			}
		}
		double ans = 0;
		sort(edges.begin(), edges.end());
		for(auto& p : edges)
		{
			cout << get<1>(p) << " " << get<2>(p) << " " << get<0>(p) << endl;
			if(find_parent(get<1>(p)) != find_parent(get<2>(p)))
			{
				ans += get<0>(p);
				unite(get<1>(p), get<2>(p));
			}
		}
		printf("%.2f\n", ans/100.0);
	}
	return 0;
}
