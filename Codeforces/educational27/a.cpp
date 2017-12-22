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
	vi vec(2*n);
	rp(i,2*n) scanf("%d", &vec[i]);
	sort(all(vec));
	vi win;
	rp(i, n){
		int last = vec.back();
		win.pb(last);
		vec.pop_back();
	}
	reverse(all(vec));
	reverse(all(win));
	bool ok = true;
	rp(i, n){
		if(win[i] == vec[i]){
			ok = false;
			break;
		}
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}

