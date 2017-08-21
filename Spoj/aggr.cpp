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
typedef vector<ll> vll;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int maxn = 1e5 + 5;
int n, m;
vll st;

bool f(ll d){
	int c = m;
	ll prev = -10000000;
	while(c--){
		auto it = lower_bound(all(st), prev+d);
		if(it == st.end()) return false;
		else prev = *(it);
	}
	return true;
}

void doit(){
	cin >> n >> m;
	st.resize(n);
	rp(i, n) cin >> st[i];
	sort(all(st));
	ll lo = 0, hi = st[n-1]-st[0];
	while(lo < hi){
		ll mid = (hi + lo + 1) >> 1;
		if(f(mid)) lo = mid;
		else hi = mid-1;
	}
	cout << lo << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) doit();
	return 0;
}

