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

int n;
vi team;

ll doit(){
	sort(all(team));
	deque<int> rem;
	if(n == 1) return team[0];
	ll resp = 0;
	for(const int& v : team) rem.push_back(v);
	while(!rem.empty()){
		if(sz(rem) == 2){
			rem.pop_front();
			resp += rem.front();
			return resp;
		}
		else if(sz(rem) == 3){
			int sm = rem.front();
			rem.pop_front();
			int sm2 = rem.front();
			rem.pop_front();
			int sm3 = rem.front();
			rem.pop_front();
			if(sm > sm2) swap(sm, sm2);
			resp += sm + sm2 + sm3;
		}
		else{
			int sm1 = rem.front();
			rem.pop_front();
			int sm2 = rem.front();
			rem.pop_front();
			int lg1 = rem.back();
			rem.pop_back();
			int lg2 = rem.back();
			rem.pop_back();
			
			ll r1 = 2*sm2*1ll + sm1 + lg1; 
			ll r2 = 2*sm1*1ll + lg1 + lg2;
			rem.push_front(sm2);
			rem.push_front(sm1);
			resp += min(r1, r2);
		}
	}
	return resp;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	team.assign(n, 0);
	rp(i, n) cin >> team[i];
	cout << doit() << endl;
}
