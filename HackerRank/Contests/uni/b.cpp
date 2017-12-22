/*input
10
2
3 3 3 
7 7 4
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
const int maxn = 301;

int grid[maxn][maxn] = {{0}};
int acc[maxn][maxn] = {{0}};
int n, v, x, y, p;

void propagate(int a, int b, int c){
	if(grid[a][b] > c)return;
	rp(i, n){
		rp(j, n){
			int mx = max(abs(a-i), abs(b-j));
			grid[i][j] += max(0, c - mx);
		}
	}
}
int main(){
	scanf("%d", &n);
	scanf("%d", &v);
	while(v--){
		scanf("%d %d %d", &x, &y, &p);
		acc[x][y] += p;
		propagate(x, y, p);
	}
	//for(const ii& q : pt) propagate(q.fi, q.se, acc[q.fi][q.se]);
	int mx = 0;
	rp(i, n){
		rp(j, n){
			mx = max(mx, grid[i][j]);
		}
	}
	printf("%d\n", mx);
	return 0;
}

