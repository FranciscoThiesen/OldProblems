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

const int maxn = 52;

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		int c[maxn][maxn] = {{0}};
		scanf("%d %d", &n, &m);
		int ans = 0;
		fr(i,1,n+1){
			fr(j,1,m+1){
				scanf("%d", &c[i][j]);
				if(c[i][j]) ans++;
			}
		}
		fr(i, 1, n+2){
			fr(j, 1, m+2){
				ans += abs(c[i][j] - c[i-1][j]);
				ans += abs(c[i][j] - c[i][j-1]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

