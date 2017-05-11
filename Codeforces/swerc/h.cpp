#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define fi first
#define se second

#define pb push_back
#define mp make_pair


class UnionFind {
	private: vi p, rank;
	public:
		UnionFind(int N)
		{
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i = 0; i < N; ++i)
				p[i] = i;
		}
		int findSet(int i)
		{
			return (p[i] == i) ? i : (p[i] = findSet(p[i]) ) ;
		}
		bool isSameSet(int i, int j)
		{
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j)
		{
			if(!isSameSet(i, j))
			{
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y])
				{
					p[y] = x;
				}
				else
				{
					p[x] = y;
					if(rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > adjList(50001);
	vector<vector<int> > adjList2D(50001);
	vector<pair<int, int> > edgeList2D;
	vector<pair<int, int> > edgeList;
	vector<pair<pair<int, int>, int > > coordinates;
	vector<pair<int, int> > coordinates2d;
	for(int i = 0; i < n; ++i)
	{
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int idx1 = -1;
		int idx2 = -1;
		int idx1_2d = -1;
		int idx2_2d = -1;
		for(int j = 0; j < coordinates.size(); ++j)
		{
			if(x1 == coordinates[j].fi.fi && y1 == coordinates[j].fi.se && z1 == coordinates[j].se)
			{
				idx1 = j;
			}
			if(x2 == coordinates[j].fi.fi && y2 == coordinates[j].fi.se && z2 == coordinates[j].se)
			{
				idx2 = j;
			}
		}
		for(int j = 0; j < coordinates2d.size(); ++j)
		{
			if(x1 == coordinates2d[j].fi && y1 == coordinates2d[j].se)
			{
				idx1_2d = j;
			}
			if(x2 == coordinates2d[j].fi && y2 == coordinates2d[j].se)
			{
				idx2_2d = j;
			}
		}
		if(idx1 == -1)
		{
			coordinates.pb(mp(mp(x1,y1), z1));
			idx1 = coordinates.size() - 1;
		}
		if(idx2 == -1)
		{
			coordinates.pb(mp(mp(x2,y2), z2));
			idx2 = coordinates.size() - 1;
		}
		if(idx1_2d == -1)
		{
			coordinates2d.pb((mp(x1,y1)));
			idx1_2d = coordinates2d.size() - 1;
		}
		if(idx2_2d == -1)
		{
			coordinates2d.pb(mp(x2,y2));
			idx2_2d = coordinates2d.size() - 1;
		}
		if(idx1_2d != idx2_2d)
			edgeList2D.pb(mp(min(idx1_2d, idx2_2d), max(idx1_2d, idx2_2d)));
		if(idx1 != idx2)
			edgeList.pb(mp(min(idx1, idx2), max(idx1, idx2)));

	}	
	sort(edgeList.begin(), edgeList.end());
	edgeList.erase( unique( edgeList.begin(), edgeList.end() ), edgeList.end() );

	sort(edgeList2D.begin(), edgeList2D.end());
	edgeList2D.erase( unique( edgeList2D.begin(), edgeList2D.end() ), edgeList2D.end() );

	bool cycle3d = false;
	UnionFind UF(50001);
	int sz = edgeList.size();
	for(int i = 0; i < sz; ++i)
	{
		ii w = edgeList[i];
		if(!UF.isSameSet(w.first, w.second))
		{
			cout << "Fiz a uniao de " << w.fi << " " << w.se << endl;
			UF.unionSet(w.first, w.second);
		}
		else
		{
			cycle3d = true;
			break;
		}
	}
	cout << endl << endl;

	int sz2 = edgeList2D.size();
	UnionFind UF2(50001);
	bool cycle2d = false;

	for(int i = 0; i < sz2; ++i)
	{
		ii w = edgeList2D[i];
		cout << UF2.findSet(w.fi) << " " << UF2.findSet(w.se) << endl;
		if(!UF2.isSameSet(w.first, w.second))
		{
			//cout << "Fiz a uniao de " << w.fi << " " << w.se << endl;
			UF2.unionSet(w.first, w.second);
		}
		else
		{
			cycle2d = true;
			break;
		}
	}

	if(cycle3d)
		cout << "True closed chains" << endl;
	else
		cout << "No true closed chains" << endl;
	if(cycle2d)
		cout << "Floor closed chains" << endl;
	else
		cout << "No floor closed chains" << endl;

	return 0;

}