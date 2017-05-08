#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <random>
#include <list>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert
typedef vector<int> vi;
struct UnionFind{
	vi parent;
	
	UnionFind(int n){
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int unions(int u, int v){
		if(finds(u) == finds(v))
			return 0;
		parent[parent[u]] = parent[v];
		return 1;
	}

	int finds(int u){
		if(u == parent[u])
			return u;
		return parent[u] = finds(parent[u]);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int e;
	cin >> e;
	map<tuple<int, int, int>, int > pts3d;
	map<pair<int, int>, int > pts2d;
	vector<unordered_set<int> > arestas3d(100001);
	vector<unordered_set<int> > arestas2d(100001);
	bool cycle3d = false;
	bool cycle2d = false;
	int global_ind = 0;
	int global_ind2 = 0;
	for(int i = 0; i < e; ++i)
	{
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		auto pt1 = make_tuple(x1, y1, z1);
		auto pt2 = make_tuple(x2, y2, z2);
		int idx1;
		int idx2;
		//vendo o caso 3d
		if(pts3d.find(pt1) != pts3d.end())
			idx1 = pts3d[pt1]; 
		else
		{
			pts3d.ins(mp(pt1, global_ind));
			idx1 = global_ind;
			global_ind++;
		}
		if(pts3d.find(pt2) != pts3d.end())
			idx2 = pts3d[pt2];
		else
		{
			pts3d.ins(mp(pt2, global_ind));
			idx2 = global_ind;
			global_ind++;
		}
		//filtrando arestas com mesma origem e destino
		if(idx1 != idx2)
			arestas3d[min(idx2, idx1)].insert(max(idx1, idx2));
		//vendo o caso 2d
		auto p1 = mp(x1, y1);
		auto p2 = mp(x2, y2);
		if(pts2d.find(p1) != pts2d.end())
			idx1 = pts2d[p1];
		else
		{
			pts2d.ins(mp(p1, global_ind2));
			idx1 = global_ind2;
			global_ind2++;
		}
		if(pts2d.find(p2) != pts2d.end())
			idx2 = pts2d[p2];
		else
		{
			pts2d.ins(mp(p2, global_ind2));
			idx2 = global_ind2;
			global_ind2++;
		}
		if(idx1 != idx2)
			arestas2d[min(idx2, idx1)].insert(max(idx2, idx1));
	}
	UnionFind uf2d(pts2d.size());
	for(int i = 0; i < pts2d.size(); ++i)
	{
		if(cycle2d)
			break;
		for(auto& p : arestas2d[i])
		{
			if(uf2d.finds(i) == uf2d.finds(p))
			{
				cycle2d = true;
				break;
			}
			else
				uf2d.unions(i, p);

		}
	}
	UnionFind uf3d(pts3d.size());
	for(int i = 0; i < pts3d.size(); ++i)
	{
		if(cycle3d)
			break;
		for(auto& p : arestas3d[i])
		{
			if(uf3d.finds(i) == uf3d.finds(p))
			{

				cycle3d = true;
				break;
			}
			else
				uf3d.unions(i, p);
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