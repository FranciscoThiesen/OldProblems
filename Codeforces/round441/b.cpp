/*input
4 3 5
2 7 7 7
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

int main(){
	int n, m, k;
	cin >> n >> k >> m;
	vector<vector<int> > rem(m);
	rp(i, n){
		int x;
		cin >> x;
		rem[x%m].pb(x);
	}
	rp(i, m){
		int tam = (int)rem[i].size();
		if(tam >= k){
			cout << "Yes" << endl;
			rp(j, k){
				cout << rem[i][j] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}

