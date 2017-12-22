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
const int mod = 1e9 + 7;

int dp[51][100000+5];
int main(){
	int t, m, n;
	scanf("%d %d %d", &t, &m, &n);
	fr(i, m, n+1)dp[0][i] = 1;
	fr(i, 1, t){
		fr(j, m, n+1){
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%mod;
		}
	}
	int rsp = 0;
	fr(j, m, n+1)rsp = (rsp + dp[t-1][j])%mod;
	printf("%d\n", rsp);
}

