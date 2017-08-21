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

vector<vi> g(200010);
vi v(200010);
int pos;
vi vis(200010, 0);

bool dfs(int v) {
	if(v == pos)
	 return true;
	bool ret = false;
	vis[v] = 1;
	for(auto p : g[v]) {
		if(!vis[p])
			ret = dfs(p);
			if(ret) return true;
	}
	return ret;
}
int main(){
	int n;
	cin >> n;
	rp(i,n) {
		cin >> v[i];
	}
	int k;
	cin >> k;
	rp(i,k) {
		rp(i, n) {
			int a;
			cin >> a;
			g[a-1].pb(i);
		}
	}
	int x;
	cin >> x;
	rp(i,n) if(v[i] == x) pos = i;
	bool ok = dfs(0);
	if(ok) cout << "YES" << "\n";
	else cout << "NO" << "\n";
	return 0;
}

