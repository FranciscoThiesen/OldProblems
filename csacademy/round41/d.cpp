/*input
2 1 1
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

int n, m, k;
int main(){
	scanf("%d %d %d", &n, &k, &m);
	int qntd = (1 << n);
	set<int> rem;
	rp(i, qntd) rem.insert(i+1);


	vi ans(qntd, 0);
	ans[0] = k;
	int win = m;
	int start = 1;
	int sz = 1;
	rem.erase(k);

	bool pos = true;
	while(win){
		for(int i = start; i < start+sz; ++i){
			int nxt = *(rem.begin());
			if(nxt > k){
				puts("-1");
				return 0;
			}
			else{
				ans[i] = nxt;
				rem.erase(rem.begin());
			}
		}
		start = start+sz;
		sz *= 2;
		win--;
	}
	if(start == qntd){
		rp(i, qntd){
			printf("%d ", ans[i]);
		}
		puts("");
		return 0;
	}
	else{
		auto q = rem.upper_bound(k);
		if(q == rem.end()){
			puts("-1");
			return 0;
		}
		else{
			ans[start] = *q;
			rem.erase(q);
			rp(i, qntd){
				if(ans[i] != 0)
					printf("%d ", ans[i]);
				else break;
			}
			while(!rem.empty()){
				printf("%d ", *(rem.begin()));
				rem.erase(rem.begin());
			}
			puts("");
		}
	}
	return 0;
}

