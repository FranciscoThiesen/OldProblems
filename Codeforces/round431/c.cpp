/*input
17
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

vector<int> can;

int main(){
	int tot = 1;
	int inc = 2;
	while(tot < 100000){
		can.pb(tot);
		tot += inc;
		inc++;
	}
	int k;
	scanf("%d", &k);
	if(k == 0){
		puts("a");
		return 0;
	}
	vector<int> freqs;
	while(k){
		int idx = upper_bound(all(can), k) - can.begin() - 1;
		k -= can[idx];
		freqs.pb(idx+2);
	}
	for(int i = 0; i < freqs.size(); ++i){
		char c = 'a' + i;
		rp(j, freqs[i]){
			printf("%c", c);
		}
	}
	puts("");
	return 0;
}

