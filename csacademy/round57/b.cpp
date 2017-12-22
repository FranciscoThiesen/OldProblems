/*input
1 2
01110
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
#define init() ios::sync_with_stdio(0);cin.tie(0);
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;


int main(){
	init();
	ll s, t;
	cin >> s >> t;
	string n;
	cin >> n;
	vector<ii> freq;
	int cur = n[0]-'0';
	int sz = 1;
	int bst = 0;
	for(int i = 1; i < s; ++i){
		if(n[i]-'0' == cur){
			sz++;
		}
		else{
			if(cur == 0){
				bst = max(bst, sz);
			}
			freq.pb(mp(cur, sz));
			sz = 1;
			cur = !cur;
		}
	}
	if(cur == 0){
		bst = max(bst, sz);
	}
	if(t == 1){
		cotu << bst << endl;
		return 0;
	}
	freq.pb(mp(cur, sz));
	if(bst == s){
		ll resp = s;
		resp *= t;
		cout << resp << endl;
		return 0;
	}
	freq.pb(mp(cur, sz));
	if(sz(freq) > 2){
		int can = bst;
		if(freq[0].fi == 0 && freq[sz(freq)-1].fi == 0){
			can = freq[0].se + freq[sz(freq)-1].se;
			can = max(bst, can);
		}
		cout << can << endl;
		return 0;
	}
	else cout << bst << endl;

	return 0;
}

