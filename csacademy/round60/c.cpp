/*input
4 5 3
0 3 4
0 4 1
2 1 0
1 2 2
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i) = (a); (i) < (n); ++(i))
#define per(i,a,n) for(int (i) = (n-1); (i) >= (a); --(i))
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define SZ(a) ((int)(a.size()))
#define init() ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;
const int maxn = 1e5 + 2;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }


int taken;
vector<int> g[maxn];
vector<int> color(maxn, 0);
vector<int> number(maxn, -1);
bool cycle = false;
bool ok2 = true;

void dfs(int root){
	// vamos colorir comecando da raiz
	color[root] = 1; // raiz cinza
	for(const int& v : g[root]){
		if(color[v] == 1){ // se a cor de um vizinho for cinza, achamos ciclo
			cycle = true;
			return;
		}
		if(color[v] == 0) dfs(v); // se tem vizinho branco, temos que colorir
		if(cycle) return; // se tem ciclo, return
	}
	color[root] = 2; // processamos a raiz ok...
}

void dfs2(int root){
	// para cada vizinho que precisa ser maior que x, vamos visita-lo, resolver pra ele, e depois estipular a cor de root
	for(const int& v : g[root])
		if(number[v] == -1) dfs2(v);
	number[root] = taken--;
}

int main(){
	init();
	vi not0(maxn, 0);
	int n, k, m, x;
	cin >> n >> k >> m;
	vector<vi> digs(n);
	taken = k-1;
	rep(i,0,n){
		rep(j,0,m){
			cin >> x;
			digs[i].pb(x);
		}
	}
	
	//vector<bool> visited(k, false);
	rep(i,1,n){
		bool valeu = false;
		rep(q, 0, m){
			if(q == 0) not0[digs[i][q]] = 1;
			if(digs[i][q] != digs[i-1][q]){
				g[digs[i-1][q]].pb(digs[i][q]);
				valeu = true;
				break;
			}
		}
		// se temos 2 numeros identicos, a resposta deve ser -1, pois nao da pra ser estritamente crescente
		if(!valeu){
			cout << -1 << endl;
			return 0;
		}
	}

	rep(i,0,k){
		if(!color[i])dfs(i);
	}
	if(cycle){
		cout << -1 << endl;
		return 0;
	}
	rep(i,0,k){
		if(number[i] == -1 && not0[i] == 1) dfs2(i);
	}
	rep(i,0,k){
		if(number[i] == -1) dfs2(i);
	}
	bool nice = true;
	rep(i,0,k){
		if(not0[i] && number[i] == 0){
			//cout << i << " " << number[i] << endl;
			cout << -1 << endl;
			return 0;
		}
	}
	// rep(i,0,k){
	// 	for(const int& v : g[i]){
	// 		if(number[v] <= number[i]){
	// 			cout << -1 << endl;
	// 			return 0;
	// 		}
	// 	}
	// }
	// rep(i,0,k){
	// 	if(number[i] < 0){
	// 		cout << -1 << endl;
	// 		return 0;
	// 	}
	// }
	// rep(i,1,n){
	// 	bool valeu = false;
	// 	rep(q, 0, m){
	// 		//cout << number[digs[i][q]].
	// 		if(digs[i][q] != digs[i-1][q]){
	// 			if(number[digs[i][q]] < number[digs[i-1][q]]){
	// 				cout << -1 << endl;
	// 				return 0;
	// 			}
	// 			valeu = true;
	// 			break;
	// 		}
	// 	}
	// 	// se temos 2 numeros identicos, a resposta deve ser -1, pois nao da pra ser estritamente crescente
	// 	if(!valeu){
	// 		cout << -1 << endl;
	// 		return 0;
	// 	}
	// }
	rep(i,0,k) cout << number[i] << " ";
	cout << endl;
	return 0;
}

