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
#define rp(a, b) fr(a,0,b)
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

int t, n, m, a, b;

constexpr int maxn = 21;
vvi adjList(maxn);
vi visited(maxn, false);

void printDfs(int root, int lvl)
{
	visited[root] = true;
	for(int i = 0; i < lvl;++i)
		printf("  ");
	for(auto v : adjList[root])
	{
		printf("%d-%d pathR(G,%d)\n", root,v,v);
		printDfs(v, 1 + lvl);
	}
	puts("\n");
}
int main()
{
	scanf("%d", &t);
	while(t--){
		rp(i,maxn)adjList[i].clear();
		fill(all(visited), false);
		scanf("%d %d", &n, &m);
		rp(i,m){
			scanf("%d %d", &a, &b);
			adjList[a].pb(b);
		}
		rp(i,n){
			if(!visited[i])
				printDfs(i,1);
		}
	}
	return 0;
}
