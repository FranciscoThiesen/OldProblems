#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

vector<bool> visited(2*50000, false);


bool findCycle(vector<vector<int> >& adjList, int root, int father)
{
	visited[root] = true;
	bool ans = false;
	for(auto& p : adjList[root])
	{
		if(!visited[p])
		{
			ans = findCycle(adjList, p, root);
		}
		else if(visited[p] && p != father)
		{
			return true;
		}
	}
}

bool findCycle2D(vector<set<int> >& adjList, int root, int father)
{
	visited[root] = true;
	bool ans = false;
	for(auto& p : adjList[root])
	{
		if(!visited[p])
		{
			ans = findCycle2D(adjList, p, root);
		}
		else if(visited[p] && p != father)
		{
			return true;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int > > pts;
	vector<pair<int,int > > pts2D;
	vector<vector<int> > adjList(100000);
	vector<set<int> > adjList2D(100000);
	for(int i = 0; i < n; ++i)
	{
		int x,y,z,a,b,c;
		cin >> x >> y >> z >> a >> b >> c;
		int idx1 = -1;
		int idx2 = -1;
		int idx1_2d = -1;
		int idx2_2d = -1;
	
		for(int j = 0; j < pts.size(); ++j)
		{
			if(x == pts[j].fi.fi && y== pts[j].fi.se && z == pts[j].se)
			{
				idx1 = j;
			}
			if(a== pts[j].fi.fi && b== pts[j].fi.se && c == pts[j].se)
			{
				idx2 = j;
			}
		}
		for(int j = 0; j < pts2D.size(); ++j)
		{
			if(x == pts2D[j].fi && y == pts2D[j].se)
			{
				idx1_2d = j;
			}
			if(a == pts2D[j].fi && b ==pts2D[j].se)
			{
				idx2_2d = j;
			}
		}
		if(idx1 == -1)
		{
			pts.pb(mp(mp(x,y),z));
			idx1 = pts.size() - 1;
		}
		if(idx2 == -1)
		{
			pts.pb(mp(mp(a,b),c));
			idx2 = pts.size() - 1;
		}
		if(idx1_2d == -1)
		{
			pts2D.pb(mp(x,y));
			idx1_2d = pts2D.size() - 1;
		}
		if(idx2_2d == -1)
		{
			pts2D.pb(mp(a,b));
			idx2_2d = pts2D.size() - 1;
		}
		adjList2D[idx1_2d].insert(idx2_2d);
		adjList2D[idx2_2d].insert(idx1_2d);
		adjList[idx1].pb(idx2);
		adjList[idx2].pb(idx1);
	}
	bool c1 = findCycle(adjList, 0, -1);
	if(c1)
		cout << "True closed chains" << endl;
	else
		cout << "No true closed chains" << endl;
	fill(visited.begin(), visited.end(), false);
	bool c2 = findCycle2D(adjList2D, 0, -1);
	if(c2)
		cout << "Floor closed chains" << endl;
	else
		cout << "No floor closed chains" << endl;
	return 0;
}