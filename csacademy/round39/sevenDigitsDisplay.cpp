#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define sz(v) (v).size()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;

vi segs{6,2,5,5,4,5,6,3,7,6};

int numDigs(int n){
	int ret = n/7;
	ret += (n%7)?1:0;
	return ret;
}

void upd(string& sol, string& cur){
	if(sz(sol) < sz(cur)) return;
	if(sz(cur) < sz(sol)){
		sol = cur;
		return;
	}
	for(int i = 0; i < sz(sol); ++i){
		if(sol[i] > cur[i]){
			sol = cur;
			return;
		}
		if(cur[i] > sol[i]) return;
	}
}

int tmp, k, dig, n;
main(){
	int need[1001];
	int tmp = 0;
	for(int i = 1; i < 1001; ++i){

		tmp = 0;
		k = i;
		while(k > 0){
			dig = k%10;
			tmp += segs[dig];
			if(!k) break;
			k /= 10;
		}
		need[i] = tmp;
	}
	cin >> n;
	if(n < 2){
		cout << "-1" << endl;
	}
	else if(n == 6){
		cout << "0" << endl;
	}
	else{
		int qntDigs = numDigs(n);
		string sol;
		string cur;
		for(int i = 1; i < 1001; ++i){
			if(need[i] > n) continue;
			int rem = n-need[i];
			if(rem%7 == 0){
				cur = to_string(i);
				int ap = rem/7;
				rp(i, ap) cur += '8';
				if(sol.empty()) sol = cur;
				else upd(sol, cur);
			}
		}
		cout << sol << endl;
	}
}