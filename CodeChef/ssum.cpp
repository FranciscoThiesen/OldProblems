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

const int maxn = 1e6 + 5;

ll A[maxn], B[maxn], dp[2][maxn];
int n;

main(){
	scanf("%d", &n);
	rp(i, n){
		scanf("%lld", &A[i]);
		dp[0][i] = A[i];
	}
	rp(i, n) scanf("%lld", &B[i]);
	fr(i, 1, n){
	
	}
}
