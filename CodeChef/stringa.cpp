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
set<int> g[maxn];
int ans[maxn];
set<pair<int, int>> e;
bool ok = true;

void fill(int root){
	int k = ans[root];
	if(k == -1){
		ok = false;
		return;
	}
	for(int s : g[root]){
		if(ans[s] == -1){
			ans[s] = k++;
		}
	}
}
 
bool checkEdges(){
	unordered_map<int, queue<int> > fila;
	int count = 0;
	fr(i,1,n + 1){
		fila[ans[i]].push(i);
	}
	for(auto v : fila){
		if(e.find(mp(0, v.se.front())) == e.end()){
			return false;
		}
		count++;
	}
	fr(i,1,n+1){
		fila[ans[i]].front();
		fila[ans[i]].pop();
		if(fila[ans[i]].empty()){
			fila.erase(ans[i]);
		}
		for(const auto& v : fila){
			if(!v.se.empty()){
				if(e.find(mp(i, v.se.front())) == e.end()){
					return false;
				}
				count++;
			}
		}
	}
	return (count == m);
}
 
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		memset(ans, -1, sizeof ans);
		rp(i, n+1){
			g[i].clear();
		}
		rp(i, m){
			scanf("%d %d", &x, &y);
			g[x].ins(y);
			e.ins(mp(x,y));
		}
		ans[0] = 1;
		ok = true;
		rp(i, n+1){
			if(!ok) break;
			fill(i);
		}
		if(ok) ok = checkEdges();
		if(ok){
			fr(i, 1, n+1){
				printf("%d ", ans[i]);
			}
		}
 
		else printf("-1");
		puts("");
		e.clear(); 
	}
	return 0;
}
 
