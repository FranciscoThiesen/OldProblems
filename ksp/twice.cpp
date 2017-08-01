#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define ins insert
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

string s;
string c = "99887766554433221100";

vector<int> freq(10, 0);
string solve(){
	if(s.size() > 20) return c;
	int sz = (int)s.size();
	
	for(int i = sz-1; i >= 0; --i){
		string tmp = s;
		fill(all(freq), 0);
		bool feasible = true;
		for(int pos = 0; pos <= i; ++pos){
			if(freq[s[pos] - '0'] == 2){
				feasible = false;
				break;
			}
			freq[s[pos] - '0']++;
		}
		if(!feasible) continue;
		if(i + 1 == sz) return s;
		else if(s[i+1] == '0') continue;
		int dig = s[i+1] - '0';
		feasible = false;
		for(int j = dig-1; j >= 0; --j)
		{
			if(freq[j] < 2){
				freq[j]++;
				tmp[i+1] = (char)'0' + j;
				feasible = true;
				break;
			}
		}
		if(!feasible) continue;
		for(int right = i+2; right < sz; ++right){
			bool ok = false;
			if(!feasible) break;
			for(int dg = 9; dg >= 0; --dg)
			{
				if(freq[dg] < 2){
					freq[dg]++;
					tmp[right] = '0' + dg;
					ok = true;
					break;
				}
			}
			if(!ok) feasible = false;
		}
		if(feasible) return tmp;
	}
	string ret = "";
	for(int i = 0; i < sz-1; ++i)
		ret += c[i];

	return ret;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		cout << solve() << endl;
	}
	return 0;
}
