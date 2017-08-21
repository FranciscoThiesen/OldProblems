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

ll solve(vector<int>& v, int k){
    ll total = 0;
    rp(i, sz(v)){
        total += v[i];
    }
    if(total%sz(v)) return -1;
    ll indi = total / sz(v);
    vector<vi> subV(k);
    rp(i, sz(v)){
        subV[i%k].pb(v[i]);
    }
	ll ans = 0;
    rp(i, k){
        ll sum = 0;
        int curSz = sz(subV[i]);
        rp(j, sz(subV[i])) sum += subV[i][j];
        if(curSz * indi != sum) return -1;
		set<pair<int, ll> > resto;
		rp(j, curSz)
		{
			if(subV[i][j] > indi){
				resto.insert(mp(j, subV[i][j] - indi));
			}
		}
    	rp(j, curSz){
			while(subV[i][j] < indi){
				auto w = *(resto.begin());
				resto.erase(resto.begin());
				if(indi - subV[i][j] <= w.se){
					if(w.se - (indi - subV[i][j]) > 0){
						resto.insert(mp(w.fi, w.se - (indi - subV[i][j])));
					}
					ans += (indi - subV[i][j]) * abs(w.fi - j);
					subV[i][j] = indi;
				}
				else{
					ans += (w.se) * abs(w.fi - j);
					subV[i][j] += w.se;
				}
			}
		}
	}
	return ans;
}

int main(){
	int t, n, e;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &e);
		vector<int> vec(n);
		rp(i, n) cin >> vec[i];
		cout << solve(vec, e) << endl;	
	}
	return 0;
}

