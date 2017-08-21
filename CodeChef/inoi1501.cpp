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

const int MAXN = 1e6 + 1;

ll a[MAXN], b[MAXN], dpL[MAXN], dpWrap[MAXN], sumB[MAXN];
int n;


int main(){
	scanf("%d", &n);
	rp(i, n){
		scanf("%lld", &a[i]);
		dpL[i] = a[i];
	}
	rp(i, n){
		scanf("%lld", &b[i]);
		if(!i) sumB[i] = b[i];
		else sumB[i] = sumB[i-1] + b[i];
	}
	fr(i, 1, n){
		dpL[i] = max(dpL[i], dpL[i-1] - a[i-1] + b[i-1] + a[i]);	
	}
}
