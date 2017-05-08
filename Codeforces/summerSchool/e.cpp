#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef pair<int, int> ii;
bool memo[201][201] = {{0}};
vector<int> order;
vector<vector<ii> > adjList(201);

void solve(int root, int idx)
{
	memo[root][idx] = true;
	//cout << root << "  " << idx << endl;
	if(idx == order.size())
		return;
	for(auto& p : adjList[root])
	{
		if(p.fi == order[idx])
		{
			if(memo[p.se][idx+1] == false)
			{
				solve(p.se, idx+1);
			}
		}
	}


}
int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n, x, k;
	in>>n;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			in >> x;
			if(x)
			{
				adjList[i].pb(mp(x, j));
				adjList[j].pb(mp(x, i));
			}
		}
	}
	in >> k;
	order.resize(k);
	for(int i = 0; i < k; ++i)
		in >> order[i];

	int resp = 0;
	set<int> ans;
	solve(0, 0);
	for(int i = 0; i < n; ++i)
	{
		if(memo[i][k])
		{
			ans.insert(i);
			resp++;
		}
	}
	out << resp << endl;
	for(auto& p : ans)
		out << p +1 << " ";
	out << endl;

}