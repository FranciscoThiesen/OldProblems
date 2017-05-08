#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, e;
	cin >> n >> e;
	if(e < n)
	{
		cout << "NO" << endl;
		return 0;
	}
	if(n == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	vector<pair<int, int> > grauInOut(n, mp(0,0));
	vector<unordered_map<int, int> > adjList(n);
	vector<pair<int, int> > edges(e);
	for(int i = 0; i < e; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--;y--;
		grauInOut[x].se++;
		grauInOut[y].fi++;
		edges[i] = mp(x, y);
		adjList[x].insert(mp(y, i));
	}
	queue<pair<int, int> > needsIn;
	vector<pair<int, int> > needsOut;
	bool pos = true;
	for(int i = 0; i < n; ++i)
	{
		if(grauInOut[i].fi > grauInOut[i].se)
		{
			needsOut.pb(mp(i, (grauInOut[i].fi - grauInOut[i].se)/2));
		}
		else if(grauInOut[i].se > grauInOut[i].fi)
		{
			needsIn.push(mp(i, (grauInOut[i].se - grauInOut[i].fi)/2));
		}
		if((grauInOut[i].fi + grauInOut[i].se)%2 != 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(grauInOut[i].fi + grauInOut[i].se == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	while(!needsIn.empty())
	{
		auto p = needsIn.front();
		//cout << p.fi+1 << " " << p.se << endl;
		for(int i = 0; i < needsOut.size(); ++i)
		{
			//cout << needsOut[i].fi+1 << " " << needsOut[i].se<< " creeeeu" << endl;
			if(needsOut[i].se > 0)
			{
				auto k = adjList[p.fi].find(needsOut[i].fi);
				if(k != adjList[p.fi].end())
				{
					//cout << "biruleibe" << endl;
					p.se--;
					needsOut[i].se--;
					edges[k->se] = mp(needsOut[i].fi, p.fi);
					adjList[p.fi].erase(k);
					if(p.se == 0)
					{
						break;
					}
				}
			}
		}
		if(p.se > 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		needsIn.pop();
	}
	cout << "YES" << endl;
	for(auto& w : edges)
		cout << w.fi+1 << " " << w.se+1 << endl;
	return 0;
}