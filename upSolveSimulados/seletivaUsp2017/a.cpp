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

const int mx = 5 * 1e4 + 5;

vi adjList[mx];
int father[mx];
int color[mx];

int n, m, k, a, b;

void dfs(int root){
	for(const int& v : adjList[root])
	{
		if(color[v] == -1){
			color[v] = (color[root]+1)%k;
			dfs(v);
		}
	}
}

void doit(){
	memset(color, -1, sizeof color);
	rp(i, n){
		if(color[i] == -1){
			color[i] = 0;
			dfs(i);
		}
	}
	rp(i, n)printf("%d\n", color[i] + 1);
}

main(){
	scanf("%d %d %d", &n, &m, &k);
	rp(i, m){
		scanf("%d %d", &a, &b);
		adjList[--a].pb(--b);
		adjList[b].pb(a);
	}
	if(k == 1 && m > 1) puts("-1");
	else if(k == 1 && m == 0) rp(i, n)puts("1");
	else doit();				
}
