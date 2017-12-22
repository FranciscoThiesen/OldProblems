/*input
3
31 28 30
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i) = (a); (i) < (n); ++(i))
#define per(i,a,n) for(int (i) = (n-1); (i) >= (a); --(i))
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define SZ(a) ((int)(a.size()))
#define init() ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }

vector<int> y{31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> y2{31,29,31,30,31,30,31,31,30,31,30,31};





int main(){
	int n;
	cin >> n;
	vi m(n);
	rep(i,0,n){
		cin >> m[i];
	}
	bool ok = false;
	// possible orders y, y, y2
	// y2, y, y
	// y, y2, y
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	for(const int& v : y){
		p1.pb(v);
		p3.pb(v);
	}
	for(const int& v : y2){
		p2.pb(v);
		p3.pb(v);
	}
	for(const int& v : y){
		p1.pb(v);
		p2.pb(v);
		p3.pb(v);
	}
	for(const int& v : y2){
		p1.pb(v);
	}
	for(const int& v : y){
		p2.pb(v);
	}
	rep(i,0,12){
		bool ok = true;
		if(m[0] == p1[i]){
			rep(j, 1, n){
				if(m[j] != p1[i+j]){
					ok = false;
					break;
				}
			}
		}
		else ok = false;
		if(ok){
			cout << "Yes" << endl;
			return 0;
		}
		ok = true;
		if(m[0] == p2[i]){
			rep(j, 1, n){
				if(m[j] != p2[i+j]){
					ok = false;
					break;
				}
			}
		}
		else ok = false;

		if(ok){
			cout << "Yes" << endl;
			return 0;
		}
		ok = true;
		if(m[0] == p3[i]){
			rep(j, 1, n){
				if(m[j] != p3[i+j]){
					ok = false;
					break;
				}
			}
		}
		else ok = false;

		if(ok){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}

