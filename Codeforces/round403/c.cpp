/*input
3
2 3
1 3
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define fu(i,n) fr(i,0,n)
#define rp(a, b) fr(a, 0 b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

int calculateMex(unordered_set<int>& Set, int col)
{
    int Mex = col;
 
    while (Set.find(Mex) != Set.end())
        Mex++;
 
    return (Mex);
}

void bfs(vector<int>& color, vvi& adjList, int root)
{
	color[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		unordered_set<int> used;
		used.insert(color[u]);
		fu(i, (int)adjList[u].size())
			if(color[adjList[u][i]] != -1)
				used.insert(color[adjList[u][i]]);
		int col = 1;
		fu(i, (int)adjList[u].size())
		{

			int v = adjList[u][i];
			if(color[v] != -1)
			{
				used.insert(color[v]);
				continue;
			}
			col = calculateMex(used, col);
			color[v] = col;
			used.insert(col);
			q.push(v);
		}
	}
}

int main()
{
	int n;
	sc(n);
	vvi adjList(n);
	vi color(n, -1);
	int ans = 0;
	int root = -1;
	fu(i, n)
	{
		int x, y;
		sc2(x,y);
		adjList[x-1].pb(y-1);
		adjList[y-1].pb(x-1);
	}
	fr(i, 0, n)
	{
		int p = (int) adjList[i].size() + 1;
		if(p + 1 > ans)
		{
			ans = p + 1;
			root = i;
		}
	}
	bfs(color, adjList, root);
	int lgst = -1;
	fr(i, 0, n)if(color[i] > lgst)lgst = color[i];
	cout << lgst << endl;
	fr(i, 0, n)cout << color[i] << " ";
	cout << endl;
	return 0;
}