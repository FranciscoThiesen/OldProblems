#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define aint(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

int dp[2020][2020];
int val[2020];

int max(int a, int b){
	return (a >= b)? a : b;
}

int t, n;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int pesoSobrando = 2*(n-1) - n;
		//vector<int> w(n);// indexando a partir de 1
		//vector<int> val(n);// indexando a partir de 1 ;; valores que importam pro knapsack
		rp(i, n-1) scanf("%d", &val[i]);	
		fr(i, 1, n) val[i] -= val[0];
		fr(elem, 0, n-1) dp[0][elem] = 0;
		// preenchendo a primeira linha da dp a parte
		fr(peso, 1, pesoSobrando+1) dp[peso][1] = val[1] * peso;
		for(int peso = 1; peso <= pesoSobrando; ++peso){
			for(int elem = 2; elem < n-1; ++elem){
				dp[peso][elem] = dp[peso][elem-1];
				if(peso - elem >= 0){
					dp[peso][elem] = max(dp[peso][elem], dp[peso - elem][elem] + val[elem]);
				}
			}
		}
		printf("%d\n", n * val[0] + dp[pesoSobrando][n-2]);
	}
	return 0;
}

