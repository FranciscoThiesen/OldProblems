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
#define ins insert
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int maxn = 1e5 + 5;

int n, m, t, x, y;
multiset<int> g[maxn];
vi ans;
set<pair<int, int> > e;

void fill(int root){
	int k = 0;
	queue<int> f;
	for(int s : g[root]){
		if(ans[s] == -1){
			ans[s] = ++k;
			f.push(s);
		}
	}
	printf("Filling %d \n", root);
	rp(i, n+1) printf("%d ", ans[i]);
	puts("");
	while(!f.empty()){
		int t = f.front();
		f.pop();
		fill(t);
	}
}

bool checkEdges(){
	map<int, queue<int> > fila;
	fr(i,1,n + 1){
		fila[ans[i]].push(i);
	}

	for(auto v : fila){
		if(e.find(mp(0, v.se.front())) == e.end()){
			return false;
		}
		e.erase(e.find(mp(0, v.se.front())));
	}
	fr(i,1,n+1){
		int idx = i;
		fila[ans[i]].front();
		fila[ans[i]].pop();
		if(fila[ans[i]].empty()){
			fila.erase(ans[i]);
		}
		for(auto v : fila){
			if(!v.se.empty()){
				if(e.find(mp(idx, v.se.front())) == e.end()){
					return false;
				}
				e.erase(e.find(mp(idx, v.se.front())));
			}
		}
	}
	if(!e.empty())
		return false;
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		ans.assign(n+1, -1);
		rp(i, m){
			scanf("%d %d", &x, &y);
			g[x].ins(y);
			e.ins(mp(x,y));
		}
		fill(0);
		bool ok = true;
		fr(i, 1, n+1){
			if(ans[i] == -1){ok = false; break;}
		if(ok) ok = checkEdges();
		if(ok){
			fr(i, 1, n+1){
				printf("%d ", ans[i]);
			}
		}

		else printf("-1");
		puts("");

		e.clear();
		rp(i, maxn) g[i].clear();
	}
	return 0;
}

