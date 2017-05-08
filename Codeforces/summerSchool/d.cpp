#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

vi lvl(1001, -1);
vector<vi > adjList(1001);
vector<int> winning(1001, -1);

void level()
{
	queue<int> q;
	q.push(1);
	lvl[1] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto& p : adjList[u])
		{
			if(lvl[p] == -1)
			{
				lvl[p] = lvl[u] + 1;
				q.push(p);
			}
		}
	}
}

bool wins(int vertex)
{
	if(winning[vertex] == 1)
		return true;
	else if(winning[vertex] == 0)
		return false;
	
	bool ret = false;
	for(auto& p : adjList[vertex])
	{
		if(lvl[p] > lvl[vertex])
		{
			if(!wins(p))
			{
				ret = true;
				break;
			}
		}
	}
	if(ret)
		winning[vertex] = 1;
	else if(!ret)
		winning[vertex] = 0;
	return ret;
}

int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n, m;
	in >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int x, y;
		in >> x >> y;
		adjList[x].pb(y);
		adjList[y].pb(x);
	}

	level();

	wins(1);
	if(winning[1])
		out << "Vladimir" << endl;
	else
		out << "Nikolay" << endl;
	in.close();
	out.close();

	return 0;
}