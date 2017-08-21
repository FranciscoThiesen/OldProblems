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

map<tuple<string, string, string>, int> memo;

bool win(string a, string b, string current){
	if(memo[mt(current, a, b)] != 0) return memo[mt(current, a, b)];
	bool aTurn = (a.size() == b.size());
	bool can = false;
	if(aTurn){
		rp(i, sz(a)){
			string tmp = a;
		}
	}
}
int main(){
	int t;
	cin >> t;
	rp(i, t){
		string x, y;
		cin >> x >> y;
		if(win(x,y)) cout << "A" << endl;
		else cout << "B" << endl;
	}
	return 0;
}

