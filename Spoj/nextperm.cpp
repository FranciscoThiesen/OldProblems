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
	int n, k;
	scanf("%d %d", &n, &k);
	vi t(n);
	rp(i, k){
		rp(i, n) cin >> t[i];
		next_permutation(all(t));
		for(const int& v : t){
			printf("%d ", v);
		}
		puts("");
	}
	return 0;
}

