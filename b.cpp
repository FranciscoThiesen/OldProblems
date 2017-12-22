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
	int msk = 1;// forcando torneira no bit 0
	int a, x, y, n, t;
	scanf("%d %d %d %d %d", &n, &t, &a, &x, &y);
	rp(i, t){
		int k;
		scanf("%d", &k);
		msk |= (1 << k);
	}
	int cur = x, cnt = 0;
	unordered_set<int> seen;
	while(1){
		while(cur != y){
			seen.insert(cur);
			cnt++;
			cur = ((__builtin_popcount(cur & msk)&1) << (n-1)) | (cur>>1);
			printf("%d\n", cur);
			if(seen.find(cur) != seen.end()){
				printf("%d = cur, %d = tamanho do ciclo\n", cur, cnt);
				break;
			}
		}

		printf("resp = %d\n", cnt);
		break;
	}
	return 0;
}

