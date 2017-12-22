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

string s;
int n[19][19] = {{0}};
int bm;
int best = -1;
string cons = "bcdfghjklmnpqrstvxz";
vector<bool> isCons(19, 0);

void calc(int bitmask){
	int ans = 0;
	rep(i,0,19){
		bool upperCase = bitmask & (1 << i);
		rep(j,0,19){
			if(i == j) continue;
			bool cse = bitmask & (1 << j);	
			if(cse == (upperCase^1)){
				ans += n[i][j];
			}
		}
	}
	if(ans > best){
		best = ans;
		bm = bitmask;
	}
}


int main(){
	ifstream in("consonant.in", ios::in);
	ofstream out("consonant.out", ios::out);
	rep(i,0,19){
		rep(j, 0, 19) n[i][j] = 0;
	}
	vi idx(26, 0);
	rep(i,0,19){
		isCons[cons[i]-'a'] = 1;
		idx[cons[i]-'a'] = i;
	}
	in >> s;
	int tam = SZ(s);
	rep(i,1,tam){
		if(isCons[s[i]-'a'] && isCons[s[i-1]-'a'])
			n[idx[s[i]-'a']][idx[s[i-1] - 'a']]++;
	}
	int limit = (1 << 19);
	rep(i,0,limit){
		calc(i);
	}
	rep(i,0,tam){
		if(isCons[s[i]-'a']){
			if(bm & (1 << (idx[s[i]-'a']))){
				out << (char)toupper(s[i]);
			}
			else out << s[i];
		}
		else out << s[i];
	}
	return 0;
}

