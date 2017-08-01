/*input
3
2 1
1 2
2 2
1 2
2 1
4 4
2 3
3 4
4 2
1 3
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

#define WHITE 0
#define GRAY 1
#define BLACK 2

constexpr int maxn = 10010;

bool cycle = false;

vector<int> color(maxn, 0);
vector<set<int> > adjList(maxn);

void dfs(int node)
{
	if(color[node] == BLACK)return;
	color[node] = GRAY;
	for(auto v : adjList[node])
	{
		if(color[v] == GRAY){
			cycle = true;
			return;
		}
		if(color[v] == WHITE)
		{
			dfs(v);	
		}
		if(cycle)break;
	}
	if(cycle)return;
	color[node] = BLACK;
	return;
}

int main()
{
	int t, n, m, a, b;
	scanf("%d", &t);
	while(t--){
		cycle = false;
		fill(color.begin(), color.end(), 0);
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &a, &b);
			adjList[a].insert(b);
		}
		for(int j = 1; j <= n; ++j){
			if(color[j] == WHITE) dfs(j);
			if(cycle)break;
		}
		if(cycle)puts("SIM");
		else puts("NAO");
		for(int i = 1; i < maxn; ++i)
			adjList[i].clear();
	}
	return 0;
}
