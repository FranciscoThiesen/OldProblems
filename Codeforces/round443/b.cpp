/*input
2 10000000000
2 1
*/
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

const int maxn = 501;
vector<int> v(maxn);
int n;
ll k;

int simulate(int qq){
	deque<ii> q;
	rp(i, n){
		q.push_back(mp(i+1, v[i]));
	}
	int curWin = 0;
	int curIdx = 0;
	rp(i, 10000){
		ii x = q.front();
		q.pop_front();
		ii y = q.front();
		q.pop_front();
		if(x.se > y.se){
			if(curIdx == x.fi){
				curWin++;
			}
			else{
				curWin = 1;
			}
			curIdx = x.fi;
			q.push_back(y);
			q.push_front(x);
		}
		else{
			if(curIdx == y.fi){
				curWin++;
			}
			else{
				curWin = 1;
			}
			curIdx = y.fi;
			q.push_back(x);
			q.push_front(y);
		}
		if(curWin == qq) return x.se;

	}
	return -1;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	v.resize(n);
	int idx = -1;
	int mx = -1;
	rp(i, n){
		cin >> v[i];
		if(v[i] > mx){
			mx = v[i];
			idx = i;
		}
	}
	if(k > 5000) cout << mx << endl;
	else{
		cout << simulate(k) << endl;
	}
	return 0;
}

