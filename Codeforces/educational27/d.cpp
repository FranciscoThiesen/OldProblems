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

int n, sp, noOvertake, rsp;

main(){
	vi spLimit;
	scanf("%d", &n);
	rp(i, n){
		int x, y;
		scanf("%d", &x);
		if(x == 1){
			scanf("%d", &sp);
			while(!spLimit.empty() && spLimit.back() < sp){
				rsp++;
				spLimit.pop_back();
			}
		}
		if(x == 2){
			rsp += noOvertake;
			noOvertake = 0;
		}
		if(x == 3){
			scanf("%d", &y);
			spLimit.pb(y);
			while(!spLimit.empty() && spLimit.back() < sp){
				rsp++;
				spLimit.pop_back();
			}
		}
		if(x == 4){
			noOvertake = 0;
		}
		if(x == 5){
			spLimit.clear();
		}
		if(x == 6){
			noOvertake++;
		}
	}
	printf("%d\n", rsp);
}
