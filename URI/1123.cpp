/*input
4 6 3 3
0 1 10
1 2 10
0 2 1
3 0 1
3 1 10
3 2 10
6 7 2 5
5 2 1
2 1 10
1 0 1
3 0 2
3 4 2
3 5 3
5 4 2
5 5 2 4
0 1 1
1 2 2
2 3 3
3 4 4
4 0 5
0 0 0 0
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

constexpr int maxn = 1e9;

int n, m, c, k, u, v, p;

bool route(int city){return (city <= c-1)? true : false;}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true)
	{
		cin >> n >> m >> c >> k;
		if(n+m+c+k==0) return 0;
		vector<vii> adjList(n);
		rp(i,m)
		{
			cin >> u >> v >> p;
			if(u > v)swap(u, v);
			if(route(u) && route(v))
			{
				if(v-u == 1)
				{
					adjList[u].pb(mp(p,v));
				}
				//adjList[v].pb(mp(p,u));
			}
			else if(route(u) && !route(v))
			{
				adjList[v].pb(mp(p,u));
			}
			else
			{
				adjList[u].pb(mp(p,v));
				adjList[v].pb(mp(p,u));
				//key idea ->
				//lets remove every edge that goes from a city on the route to a city outside the route
			}
		}
		vector<int> dist(n, maxn);
		dist[k] = 0;
		set<pair<int, int> > pq;
		pq.insert(mp(0,k));
		//cout << k << endl;
		while(!pq.empty())
		{
			pair<int, int> nxt= *(pq.begin());
			pq.erase(pq.begin());
			int node = nxt.se;
			int d = nxt.fi;
			//cout << node << " " << d << endl;

			for(auto p : adjList[node])
			{
				if(dist[p.se] == maxn)
				{
					dist[p.se] = d + p.fi;
					pq.insert(mp(d+p.fi, p.se));
				}
				else if(dist[p.se] != maxn && d + p.fi < dist[p.se])
				{
					pq.erase(mp(dist[p.se], p.se));
					dist[p.se] = d + p.fi;
					pq.insert(mp(d+p.fi, p.se));
				}
			}
		}
		cout << dist[c-1] << endl;

	}
	return 0;
}
