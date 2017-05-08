#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef vector<int> vi;
 
const double inf = 1.0/0.0;
 
#define MAXN 200001
#define MAXM 201
 
int t, n, m;
ll dp[MAXM][MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<int> elems(n);
		vector<ll> prefSum(n);
		vector<int> b(m);

		for(int i(0); i < n; ++i) {
			cin >> elems[i];	
		}
		for(int i(0); i < m; ++i) {
			cin >> b[i];	
		} 
		
		prefSum[0] = elems[0];
		for(int i = 1; i < n; ++i) {
			prefSum[i] = prefSum[i-1] + elems[i];
		}
 
 		//inicializando o ultimo turno
		for(int k = 0; k <= n - b[m-1]; ++k) {
			dp[m-1][k] = prefSum[k + b[m-1] - 1] - prefSum[k] + elems[k];
		}
		for(int turn = m-2; turn >= 0; --turn) {
			vector<ll> magic;
			vector<int> aux;
			//magic agora eh um vetor

			//para cada turno entre turn + 1 e turn + numero de remocao do turno - numero de remocao do turno anterior

			for(int i = turn+1; i < turn + b[turn] - b[turn+1]; ++i) {
				//enquanto o tamanho de magic > 0 e dp[turn+1][i] >= ultimo valor de magic
				while(magic.size() > 0 && dp[turn+1][i] >= magic.back()) {
					// tirar o ultimo valor de magic
					// tirar o ultimo valor de aux
					magic.pop_back();
					aux.pop_back();
				}
				//inserir em magic o valor do turno de cima[i], de forma similar ao que era feito antes
				magic.pb(dp[turn+1][i]);
				//inserir em aux o indice desse element
				aux.pb(i);
			}
			//int p0, nao sei o que faz
			int p0 = 0;
			//dp[turn][turn]
			dp[turn][turn] = prefSum[turn + b[turn] - 1] - prefSum[turn] + elems[turn] - magic[p0];
			for(int beg = turn + 1; beg < n - b[turn] + 1 - turn; ++beg) {
				if(aux[p0] == beg) ++ p0;
				while(int(magic.size()) > p0 && dp[turn+1][beg + b[turn] - b[turn+1] - 1] >= magic.back()) {
					magic.pop_back();
					aux.pop_back();
				}
				magic.pb(dp[turn+1][beg + b[turn] - b[turn+1] - 1]);
				aux.pb(beg + b[turn] - b[turn+1] - 1);
				dp[turn][beg] = prefSum[beg + b[turn]-1] - prefSum[beg] + elems[beg] - magic[p0];
			}
		}
		ll ans = 0;
		for(int i(0); i < n - b[0] + 1; ++i)
			ans = max(ans, dp[0][i]);
 
		cout << ans << endl;
		
	}
	return 0;
} 