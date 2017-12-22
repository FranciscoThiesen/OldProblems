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
	int n;
	scanf("%d", &n);
	vector<pair<int, char> > evts;
	int tvNeed = 0;
	rp(i, n){
		int a, b;
		scanf("%d %d", &a, &b);
		evts.pb(mp(a, 'a'));
		evts.pb(mp(b, 'c'));
	}
	sort(all(evts));
	bool ok = true;
	for(const pair<int, char>& p : evts){
		if(p.second == 'a'){
			tvNeed++;
		}
		else{
			tvNeed--;
		}
		if(tvNeed > 2) ok = false;
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}

