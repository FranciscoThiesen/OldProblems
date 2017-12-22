/*input
3 3
1 2
1 3
2 1
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
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ull moreK[maxn][11];
ull comigoEsp[maxn][11];
ull notMoreK[maxn][11];


vector<int> adjList[maxn];

int n, m, k, mx;
ull r, t;
void calcNode(int root){
	cout << "calculando pra root = " << root << endl;
	rp(i, 11){
		
		if(i == 1){
			comigoEsp[root][i] = 0;
		}
		else comigoEsp[root][i] = 0;
		moreK[root][i] = m-k;
		notMoreK[root][i] = k-1;
		// cout << "comigoEsp para i = " << i << " " << "root =  " << root <<  "->> " << comigoEsp[root][i] << endl;
		// cout << "seemEsp para i = " << i << " " << "root = "  << root << "  ->>" <<  moreK[root][i] << endl;
	}
	for(const int& v : adjList[root]){
		calcNode(v);
		fr(i, 1, 11){
			comigoEsp[root][i]; 
			r = (notMoreK[v][i-1])%mod;
			comigoEsp[root][i] += r;
			comigoEsp[root][i] %= mod;
		}
		rp(i, 11){
			r = ((m-k) * moreK[v][i]);
			t = ((m-k) * notMoreK[v][i]);
			moreK[root][i] = (moreK[root][i] + (r+t))%mod;
		}
		rp(i, 11){
			r = (comigoEsp[v][i] * (k-1)) % mod;
			t = (moreK[v][i] * (k-1)) % mod;
			notMoreK[root][i] = (notMoreK[root][i] + r+t)%mod;
		}
	}
	cout << "para o no = " << root << " os valores retornados sao " << endl;
	rp(i, 11){
		cout << comigoEsp[root][i] << endl;
	}
	cout << endl << endl;
	rp(i, 11){
		cout << moreK[root][i] << endl;
	}
	cout << endl << endl;
	rp(i, 11){
		cout << notMoreK[root][i] << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	rp(i, n-1){
		cin >> a >> b;
		if(a > b) swap(a,b);
		adjList[a-1].pb(b-1);
	}
	cin >> k >> mx;
	calcNode(0);
	ull ans = 0;
	cout << "cheguei aqui " << endl;
	rp(i, mx+1){
		ans += moreK[0][i];
		ans += comigoEsp[0][i];
		ans += notMoreK[0][i];
	}
	// rp(i, n){
	// 	cout << "no = " << i << endl;
	// 	cout << "sem ser K" << endl;
	// 	rp(j, 11){
	// 		cout << moreK[i][j] << endl;
	// 	}
	// 	cout << "Sendo K " << endl;
	// 	rp(j, 11){
	// 		cout << comigoEsp[i][j] << endl;
	// 	}
	// }
	cout << ans << endl;
	return 0;
}

