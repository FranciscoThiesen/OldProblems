/*input

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
string x;

set<string> vars;


int main(){
	ifstream in("boolean.in", ios::in);
	ofstream out("boolean.out", ios::out);
	in >> x;
	string tmp;
	for(const char& c : x){
		if(c == '|' ){
			vars.insert(tmp);
			tmp.clear();
		}
		else tmp += c;
	}
	vars.insert(tmp);
	ll ways = 1;
	bool ceta = false;
	for(const auto& v : vars){
		if(SZ(v) == 2){
			string k;
			k += v[1];
			if(vars.find(k) != vars.end()){
				ceta = true;
				ways >>= 1;
			}
		}
		ways <<= 1;
	}
	if(ceta) out << ways << endl;
	else out << ways - 1 << endl;
	return 0;
}

