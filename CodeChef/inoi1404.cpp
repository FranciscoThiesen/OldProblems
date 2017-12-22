/*input

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
#define init ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 20011;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

const int N = 313;

int grid[N][N], r, c, d;
ll dp[N][N][N][2];
// dp(i, j, k) how many ways to get to position using k consecutive moves 0-down, 1-right

int main(){
	init
	cin >> r >> c >> d;
	rep(i,0,r){
		rep(j,0,c){
			cin >> grid[i][j];
		}
	}
	if(r == 1 && c == 1){
		cout << 1 << endl;
		return 0;
	}
	dp[0][0][0][0] = dp[0][0][0][1] = 1;
	// vamos computar a primeira linha e a primeira coluna por simplicidade
	rep(col, 1, c){
		dp[0][col][col][1] = (col <= d && grid[0][col-1] == 1)? dp[0][col-1][col-1][1] : 0;
	}
	rep(row, 1, r){
		dp[row][0][row][0] = (row <= d && grid[row-1][0] == 1)? dp[row-1][0][row-1][0] : 0;
	}
	// Preciso agora conferir a corretude dessa parte, pq a de cima ta ok
	rep(row, 1, r){
		rep(col, 1, c){
			if(grid[row][col] == 0) continue;
			rep(x, 0, d+1){
				dp[row][col][1][0] = (dp[row][col][1][0] + (grid[row-1][col] ? dp[row-1][col][x][1] : 0)) % mod;
				dp[row][col][1][1] = (dp[row][col][1][1] + (grid[row][col-1] ? dp[row][col-1][x][0] : 0)) % mod;
			}
			rep(x, 2, d+1){
				dp[row][col][x][0] = (dp[row][col][x][0] + (grid[row-1][col] ? dp[row-1][col][x-1][0] : 0)) % mod;
				dp[row][col][x][1] = (dp[row][col][x][1] + (grid[row][col-1] ? dp[row][col-1][x-1][1] : 0)) % mod;
			}
		}
	}
	ll ans = 0;
	rep(i, 1, d+1) ans = (ans + dp[r-1][c-1][i][0] + dp[r-1][c-1][i][1])%mod;
	cout << ans << endl;
	return 0;
}

