#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

const int maxn = 101;

vi adjList[maxn];
int n, m, id, tot;
string s, a, b;
bool visited[maxn];
ii edg;

void dfs(int root){
	visited[root] = 1;
	tot++;
	for(const int& v : adjList[root]){
		if(!visited[v] && (root != edg.fi || v != edg.se)){
			dfs(v);
		}
	}
}

bool checkOk(){
	memset(visited, 0, sizeof visited);
	tot = 0;
	dfs(0);
	return n == tot;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m){
		if(!(n+m)) break;
		id = 0;
		map<string, int> nome;
		vector<string> rev;
		vector<ii> revEdg;
		set<ii> edge;
		set<ii> blackList;
		rp(i, n){
			cin >> s;
			rev.pb(s);
			nome[s] = id++;
		}
		vi skip;
		rp(i, m){
			cin >> a >> b;
			int x = nome[b];
			int y = nome[a];
			if(edge.find(mp(x,y)) != edge.end()){
				blackList.insert(mp(x,y));
			}
			revEdg.pb(mp(x, y));
			adjList[x].pb(y);
			edge.insert(mp(x,y));
		}
		bool one = false;
		rp(i, m){
			if(blackList.find(revEdg[i]) != blackList.end()) continue;
			edg = revEdg[i];
			if(!checkOk()){
				cout << rev[revEdg[i].se] << " " << rev[revEdg[i].fi] << endl;
				one = true;
			}
		}
		if(!one) cout << "Nenhuma" << endl;
		cout << endl;

		rp(i, maxn) adjList[i].clear();
	}
}

