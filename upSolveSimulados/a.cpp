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


int solve(int a, int b){
	int r = 0;
	while(a > b){
		r = a/b;
		a %= b;
	}
	r += (a <= 1)? 0 : 1;
	return r;
}
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	if(n == 1){
		printf("0\n");
	}
	else if(k == 1){
		printf("%d\n", n-1);
	}
	else if(n == k) printf("-1\n");
	else printf("%d\n", solve(n, k));
	return 0;
}

