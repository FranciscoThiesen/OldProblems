/*input
2 3 2 55
20 30
40 30 1
2 3
1 3
*/
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
constexpr int maxn = 205;
int d, p, r, b, a, S;

vi adjList[maxn];
int cost[maxn];
vi v(maxn, false);

ii cc(int root){
	// dado um vertice do DSP, vamos retornar quantos politicos ganhamos 
	// nessa componente conexa, e quanto temos que pagar com todas as trocas
	int qntd = 0;
	int preco = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int k = q.front();
		q.pop();
		v[k] = true;
		if( k < 100 ) qntd--;
		else qntd++;
		preco += cost[k];
		for(const int& e : adjList[k]){
			if(!v[e]){
				q.push(e);
			}
		}
	}
	return mp(qntd, preco);
}
// a ideia se resume a knapsack
int main(){
	scanf("%d %d %d %d", &d, &p, &r, &S);
	rp(i, d) scanf("%d", &cost[i]);
	rp(i, p) scanf("%d", &cost[i+100]);
	rp(i, r){
		scanf("%d %d", &a, &b);
		--a; --b;
		adjList[a].pb(100 + b);
		adjList[100 + b].pb(a);
	}
	cout << "cheguei aqui" << endl;
	vector<ii> itens;
	int tot = d;
	rp(i, maxn){
		if(!v[i]){
			itens.pb(cc(i));
		}	
	}
	cout << "sai daqui" << endl;
	int tam = (int) itens.size();
	
	int dp[S+1][tam+1] = {{0}};
	int mx = -1;
	rp(peso, S+1){
		fr(item, 1, tam+1){
			if(peso < itens[item].se) continue;
			dp[peso][item] = max(dp[peso][item-1], dp[peso - itens[item-1].se][item-1] + itens[item-1].fi); 
			mx = max(mx, dp[peso][item]);
		}
	}
	rp(peso, S+1){
		rp(item, tam){
			cout << dp[peso][item] << " ";
		}
		cout << endl;
	}
	cout << "seu buceta" << endl;
	printf("%d", mx + d);
	mx = -1;
	fill(all(v), -1);
	memset(dp, 0, sizeof(dp));
	for(auto v : itens){
		v.fi = -v.fi;
	}
	rp(peso, S+1){
		fr(item, 1, tam+1){
			if(peso < itens[item].se) continue;
			dp[peso][item] = max(dp[peso][item-1], dp[peso - itens[item-1].se][item-1] + itens[item-1].fi); 
			mx = max(mx, dp[peso][item]);
		}
	}
	printf(" %d\n", p + mx);
	return 0;
}

