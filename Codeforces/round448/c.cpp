/*input
4
1 1 1 1
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

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

int n;
int mask[72];
ll f[2][72];
// f[0][i] -> De quantas formas posso escolher i um numero par de vezes
// f[1][i] -> De quantas formas posso escolher i um numero impar de vezes

// dp[i][j] -> De quantas formas podemos escolher elementos <= i, tal que o produto tem 
// somente numeros primos em grau impar aonde o numero j possui o bit 1 ligado na representacao binaria
ll dp[2][1 << 20];

bool checkPrime(int n){
	for(int i = 2; i*i <= n; ++i) if(!(n%i)) return false;
	return true;
}

// construindo a mascara
void memo()
{
	rep(i,0,72) f[0][i] = 1;
	int cnt = 0;
	rep(i,2,72){
		if(!checkPrime(i)) continue;
		rep(j, 1, 72){
			int x = j;
			while(x%i == 0){
				x /= i;
				mask[j] ^= (1 << cnt);
			}
		}
		cnt++; // increasing the index of the prime
	}
}

int main(){
	init();
	memo();
	cin >> n;
	rep(i,0,n){
		int x;
		cin >> x;
		f[0][x] = f[1][x] = (f[0][x] + f[1][x])%mod; // forma muito inteligente de computar (:
	}

	dp[0][0] = 1;
	rep(i,0,71){
		int nxt = (i+1)%2;
		int cur = i%2;
		rep(msk, 0, (1 << 20)){
			dp[nxt][msk ^ mask[i]] = dp[nxt][msk^mask[i]] + dp[cur][msk] * f[1][i];
			dp[nxt][msk] = dp[nxt][msk] + dp[cur][msk] * f[0][i];
			if(dp[nxt][msk^mask[i]] >= mod) dp[nxt][msk ^ mask[i]] %= mod;
			if(dp[nxt][msk] >= mod) dp[nxt][msk] %= mod;
		}
		rep(msk, 0, (1 << 20)){
			dp[cur][msk] = 0;
		}
	}
	cout << (dp[1][0] - 1 + mod) % mod << endl;
	return 0;
}

