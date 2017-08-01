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
const int maxn = 1e6;

vector<char> p(1e3+1, true);
vi primes;

void sieve(){
	p[0] = p[1] = false;
	for(int i = 2; i*i < maxn; ++i){
		if(p[i]){
			primes.pb(i);
			for(int j = i*i; j*j < maxn; j += i){
				if(j > 1e3) break;
				p[j] = false;
			}
		}
	}
}

int fact(int n){
	int rsp = 0;
	while(n > 1){
		for(int v : primes){
			if(v*v > n) break;
			while(n%v == 0){
				rsp++;
				n /= v;
			}	
		}
		break;
	}
	if(n > 1)rsp++;
	return rsp;
}

main(){
	sieve();
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int cur = 0;
		rp(i, n){
			int x;
			scanf("%d", &x);
			cur ^= fact(x);
		}
		if(cur) puts("1");
		else puts("2");
	}
}
