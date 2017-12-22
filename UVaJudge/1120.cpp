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

ll x;
ll phi(ll n){
	ll result = n;
	for(ll i = 2; i*i <= n; ++i){
		while(!(n%i)){
			n /= i;
		}
		result -= result/i;
	}
	if(n > 1) result -= result/n;
	return result;
}

int main(){
	while(scanf("%lld", &x) == 1){
		printf("%lld\n", phi(x));
	}
	return 0;
}

