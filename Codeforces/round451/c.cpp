/*input
4
ivan 3 123 123 456
ivan 2 456 456
ivan 8 789 3 23 6 56 9 89 2
dasha 2 23 789
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


struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        if(a.length() != b.length()) return a.length() < b.length();
    	else return a <= b;
    }
};

struct lexicographical_cmp{
	bool operator()(const string& a, const string& b) const{
		int sz = min(SZ(a), SZ(b));
		rep(i,0,sz){
			if(a[i] != b[i]){
				return a[i] < b[i];
			}
		}
		return SZ(a) < SZ(b);
	}
};

map<string, set<string>, lexicographical_cmp> dict;
map<string, set<string>, lexicographical_cmp > blackList;
string s, num;

// check if b is suffix of a
bool isSuffix(const string& a, const string& b){
	if(a == b) return true;
	int bt = SZ(b), at = SZ(a);
	if(bt > at) return false;
	bool ok = true;
	rep(i, 0, bt){
		ok &= (b[bt-i-1] == a[at-i-1]);
		if(!ok) break;
	}
	return ok;
}

int main(){
	init();
	int n;
	cin >> n;
	int k;
	rep(i,0,n){
		cin >> s;
		cin >> k;
		rep(i,0,k){
			cin >> num;
			bool fine = true;
			if(dict[s].find(num) != dict[s].end()) continue;
			else{
				for(const string& t : dict[s]){
					if(isSuffix(t, num)){
						fine = false;
						break;
					}
					if(isSuffix(num, t)){
						blackList[s].insert(t);
					}
				}
				if(fine){
					dict[s].insert(num);
				}
			}
		}
	}
	for(const auto& v : blackList){
		for(const string& s : v.se){
			dict[v.fi].erase(dict[v.fi].find(s));
		}
	}
	cout << SZ(dict) << endl;
	for(auto& p : dict){
		cout << p.fi << " " << SZ(p.se) << " ";
		for(const string& s : p.se) cout << s << " ";
		cout << endl;
	}
	return 0;
}

