#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)

map<string, int> rep;
string s, t;
const int maxn = 70001;
vector<string> ans(70001);

bool cmp(const string& a, const string& b){
	if(a.empty()) return true;
	return a.size() > b.size();
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	fr(k,1, n+1){
		cin >> s;
		fr(sz,1,10){
			fr(i, 0, 9 - sz + 1){
				t = s.substr(i, sz);
				if(rep[t] == 0 || rep[t] == k) rep[t] = k;
				else rep[t] = -1;
			}
		}
	}
	for(const auto& p : rep)
		if(p.se != -1)
			ans[p.se] = cmp(ans[p.se], p.fi)? p.fi : ans[p.se];
	rp(i, n) cout << ans[i+1] << endl;
}
