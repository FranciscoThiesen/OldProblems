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
	ll n;
	ll k;
	scanf("%lld %lld", &n, &k);
	vector<bool> used(n + 10, false);
	vi resp(n + 1, -1);
	rp(i, n){
		if(n-i-1 >= k){
			int diff = (n-i-1)-k;
			used[(n-i-1)-diff] = true;
			resp[i] = (n-i-1-diff);
			break;
		}else{
			k -= (n-i-1);
			used[n-i-1] = true;
			resp[i] = (n-i-1);
		}
	}
	int idx = 0;
	rp(i, n){
		if(resp[i] == -1){
			while(used[idx])idx++;
			if(idx > n) break;
			resp[i] = idx++;
		}
	}
	for(int i = 0; i < n; ++i){
		if(i != n-1) printf("%d ", resp[i] + 1);
		else printf("%d\n", resp[i] + 1);
	}
	return 0;
}

