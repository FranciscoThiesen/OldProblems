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
const int maxn = 6300005;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	vector<ll> ans(n);
	rp(i, n) cin >> v[i];
	sort(v.rbegin(), v.rend());
	queue<ll> q1, q2;
	rp(i, n) q1.push(v[i]);
	fr(i, 1, maxn){
		if(q2.empty()){
			if(q1.empty()){
				break;
			}
			ll x = q1.front();
			q1.pop();
			ans[i] = x;
			q2.push(x/2);
		}
		else if(q1.empty()){
			ll x = q2.front();
			q2.pop();
			ans[i] = x;
			q2.push(x/2);
		}
		else{
			ll x = q1.front();
			ll y = q2.front();
			if(x > y){
				ans[i] = x;
				q2.push(x/2);
				q1.pop();
			} else{
				ans[i] = y;
				q2.push(y/2);
				q2.pop();
			}
		}
	} 
	rp(i, m){
		int x; cin >> x;
		cout << ans[x] << endl;
	}	
	
}

