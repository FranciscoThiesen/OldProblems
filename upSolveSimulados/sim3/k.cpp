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
const ull limit = 1e18;
int r, s, m, d, n;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> s >> m >> d >> n;
	vector<int> brands(r);
	vector<vi> recipes(s+m+d);
	set<ii> naoRola;
	rp(i, r) cin >> brands[i];
	ull tot = 0;
	rp(i, s+m+d){
		int x, ing;
		cin >> x;
		rp(j, x){
			cin >> ing;
			recipes[i].pb(--ing);
		}
	}
	rp(i, n){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		naoRola.insert(mp(--a,--b));
	}
	fr(i, 0, s){
		fr(j, s, s+m){
			fr(k, s+m, s+m+d){
				bool a = naoRola.find(mp(i,j)) != naoRola.end();
				bool b = naoRola.find(mp(i,k)) != naoRola.end();
				bool c = naoRola.find(mp(k,j)) != naoRola.end();
				if(a || b || c) continue;
				ull tmp = 1;
				ull prev = tmp;
				set<int> vaiRolar;
				vector<ull> multi;
				for(const int& v : recipes[i]) vaiRolar.insert(v);
				for(const int& v : recipes[j]) vaiRolar.insert(v);
				for(const int& v : recipes[k]) vaiRolar.insert(v);
				for(const int& v : vaiRolar) multi.pb((ull) brands[v]);	
				for(const ull& x : multi){
					prev = tmp;
					tmp *= x;
					if(tmp/x != prev){
						cout << "too many" << endl;
						return 0;
					}
				}
				if(limit - tot < tmp){
					cout << "too many" << endl;
					return 0;
				}
				tot += tmp;
			}
		}
	}
	if(tot <= limit)
		cout << tot << endl;
	else cout << "too many" << endl;
	return 0;
}

