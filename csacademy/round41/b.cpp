/*input
001100
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

int main(){
	string s;
	cin >> s;
	vector<ii> grp;
	int n = sz(s);
	int prev = s[0] - '0';
	int sz = 1;
	int zg= 0;
	int zo = 0;
	fr(i, 1, n){
		if((s[i] - '0') == prev){
			sz++;
		}

		else{
			grp.pb(mp(prev,sz));
			if(!prev) zg++;
			else zo++;
			prev = !prev;
			sz = 1;
		}
	}
	if(prev == 0)zg++;
	else zo++;
	grp.pb(mp(prev, sz));
	int resp = 0;
	n = sz(grp);
	rp(i, n){
		if(grp[i].fi == 0){
			if(zg > 1)
				resp = max(resp, grp[i].se + 1);
			else
				resp = max(resp, grp[i].se);
			if(i+2 < n){
				if(grp[i+1].se == 1 && zg > 2)
					resp = max(resp, grp[i].se + grp[i+2].se + 1);
				else if(grp[i+1].se == 1) resp = max(resp, grp[i].se + grp[i+2].se);
			}
		}
	}
	cout << resp << endl;
	return 0;
}

