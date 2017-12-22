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

int main(){
	int r, d, n, x, y, R; 
	scanf("%d %d", &r, &d);
	scanf("%d", &n);
	int c = 0;
	rp(i, n){
		scanf("%d %d %d", &x, &y, &R);
		x = max(x, -x);
		y = max(y, -y);
		if(sqrt(x*x + y*y) - R >= (r-d) && sqrt(x*x + y*y) + R <= r){
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}

