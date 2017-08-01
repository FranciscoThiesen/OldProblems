/*input
3 1 1 0
1 2
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(v) (v).size()
#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

int main()
{
	int n, m, a, b, x, y,t;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	vector<bool> inSet(n, true);
	vvi adjList(n);
	vi A(n, 0);
	set<ii> degree;
	rp(i, m){sc2(x, y); adjList[x-1].pb(y-1); adjList[y-1].pb(x-1);}
	rp(i,n){A[i] = adjList[i].size(); degree.insert(mp(A[i], i));};
	while(true){
		if(degree.empty())break;
		t = sz(degree);
		ii top = *(degree.begin());
		bool f = false, l = false;
		if(top.fi < a)
		{
			degree.erase(degree.begin());
			inSet[top.se] = false;
			rp(i, adjList[top.se].size()){
				int idx = adjList[top.se][i];
				if(inSet[idx]){
					degree.erase(mp(A[idx], idx));
					A[idx]-=1;
					degree.insert(mp(A[idx], idx));
				}
			}	
		}
		else if(t - top.fi - 1 < b)
		{
			cout << 0 << endl;return 0;
		}
		else f = true;

		if(degree.empty())break;
		ii lst = *(degree.rbegin());
 		t = sz(degree);
		if(lst.fi < a){cout << 0 << endl;return 0;}
		else if(t - lst.fi - 1 < b){
			degree.erase(mp(lst.fi, lst.se));
			inSet[lst.se] = false;
			rp(i, adjList[lst.se].size()){
				int idx = adjList[lst.se][i];
				if(inSet[idx]){
					degree.erase(mp(A[idx], idx));
					A[idx]-=1;
					degree.insert(mp(A[idx], idx));}
			}	
		}else{l = true;}
		if(l && f)break;
	}
	cout << degree.size() << endl;
	return 0;
}
